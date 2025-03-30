#include <iostream>
#include <list>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

template <class type>
class Graph{
    vector<list<type>>unweighted_Graph;
public:
    Graph(){

    }
    Graph(int v){
        unweighted_Graph.resize(v); // Resizing the Adjacency List
    }
    void createGraph();
    void add_Edge(type src,type des);
    void display();
    void BFS(type src,unordered_set<int>& visited);
    int connectedComponent();
};

template <class type>
void Graph<type>::createGraph(){
    int v,e; // v is the number of vertices and e is number of edges
    cout<<"Please Enter the Number of Vertices :- ";
    cin>>v;
    unweighted_Graph.resize(v); // Resizing the Adjacency List
    cout<<"Please enter the number of edges in your graph:- ";
    cin>>e;
    while(e--){
        int src,des;
        cout<<"Please enter your Source:- ";
        cin>>src;
        cout<<"Please enter your destination:- ";
        cin>>des;
        this->add_Edge(src,des);
    }
}

template <class type>
void Graph<type>::add_Edge(type src,type des){
    if(src<unweighted_Graph.size() && des<unweighted_Graph.size()){
        unweighted_Graph[src].push_back(des); // Insert At End in Linked List
        unweighted_Graph[des].push_back(src); // Insert At End in Linked List
    }
    else cout<<"Invalid Vertex Entered by You\n";
}

template <class type>
void Graph<type>::display(){
    cout<<"Your Graph looks as Given Below:-\n";
    for(int i=0;i<unweighted_Graph.size();i++){
        cout<<i<<" -> ";
        int size = unweighted_Graph[i].size();
        for(auto ele: unweighted_Graph[i]){
            if(size-1)cout<<ele<<",";
            else cout<<ele;
            size--;
        }
        cout<<endl;
    }
}

template <class type>
void Graph<type>::BFS(type src,unordered_set<int>& visited){
    visited.insert(src);
    queue<type>qu;
    qu.push(src);
    cout<<"BFS Traversal is given below:-\n";
    while(not qu.empty()){
        type curr = qu.front();
        cout<<curr<<" ";
        qu.pop();
        for(auto neighbour: unweighted_Graph[curr]){
            if(not visited.count(neighbour)){
                visited.insert(neighbour);
                qu.push(neighbour);
            }
        }
    }
    cout<<endl;
}

template <class type>
int Graph<type>::connectedComponent(){
    int result = 0;
    unordered_set<int>visited;
    for(int i=0;i<unweighted_Graph.size();i++){
        if(not visited.count(i)){
            result++;
            BFS(i,visited);
        }
    }
    return result;
}

int main(){
    cout<<"\nWelcome to the world of programming\n";
    cout<<"Program is based on Unweighted Graph implementation using Adjacency List approach and templates\n";
    cout<<"In this We are finding the number of connected components in Graph using BFS Algorithm\n";
    Graph<int> G;
    G.createGraph();
    G.display();
    while(true){
        cout<<"Press 0 to exit\n";
        int choice;
        cout<<"Please enter your choice:- ";
        cin>>choice;
        if(!choice)return 0;
        int src,des;
        cout<<"Please enter the Source:- ";
        cin>>src;
        cout<<"Total number of Connected Component in your Graph:- "<<G.connectedComponent()<<endl;
    }
    return 0;
}