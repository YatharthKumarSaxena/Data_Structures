#include <iostream>
#include <list>
#include <vector>
#include <set>
using namespace std;

class Graph{
    vector<list<int>>unweighted_Graph;
public:
    Graph(){

    }
    Graph(int v){
        unweighted_Graph.resize(v); // Resizing the Adjacency List
    }
    void createGraph();
    void add_Edge(int src,int des);
    void display();
    void has_Cycle();
    bool DFS(int src,int parent,set<int>&visited);
};

void Graph::createGraph(){
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

void Graph::add_Edge(int src,int des){
    if(src<unweighted_Graph.size() && des<unweighted_Graph.size()){
        unweighted_Graph[src].push_back(des); // Insert At End in Linked List
        unweighted_Graph[des].push_back(src); // Insert At End in Linked List
    }
    else cout<<"Invalid Vertex Entered by You\n";
}

void Graph::display(){
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

bool Graph::DFS(int src,int parent,set<int>&visited){
    bool result = false;
    visited.insert(src);
    for(auto ele: unweighted_Graph[src]){
        if(visited.count(ele) && parent != ele)return true;
        if(!visited.count(ele))result= DFS(ele,src,visited);
        if(result)return true;
    }
    return false;
}

void Graph::has_Cycle(){
    bool result = false;
    set<int>visited;
    for(int i=0;i<unweighted_Graph.size();i++){
        if(! visited.count(i)){
            result = DFS(i,-1,visited);
        }
    }
    if(result)cout<<"Cycle Detected\n";
    else cout<<"No cycle exists\n";
    return;
}

int main(){
    cout<<"\nWelcome to the world of programming\n";
    cout<<"Program is dedicated to detect a Cycle in Undirected Graph using DFS\n";
    Graph G;
    G.createGraph();
    G.has_Cycle();
}