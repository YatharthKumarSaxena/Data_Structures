#include <iostream>
#include <list>
#include <vector>
using namespace std;

template<class type1,class type2>
class Graph{
    vector<list<pair<type1,type2>>>weighted_Graph;
public:
    Graph(){

    }
    Graph(int v){
        weighted_Graph.resize(v); // Resizing the Adjacency List
    }
    void createGraph();
    void add_Edge(type1 src,type1 des,type2 weight);
    void display();
    bool DFS(type1 src,type1 des,vector<bool>&visited);
    void anyPath(type1 src,type1 des);
};

template<class type1,class type2>
void Graph<type1,type2>::createGraph(){
    type1 v,e; // v is the number of vertices and e is number of edges
    cout<<"Please Enter the Number of Vertices :- ";
    cin>>v;
    weighted_Graph.resize(v); // Resizing the Adjacency List
    cout<<"Please enter the number of edges in your graph:- ";
    cin>>e;
    while(e--){
        type1 src,des;
        type2 weight;
        cout<<"Please enter your Source:- ";
        cin>>src;
        cout<<"Please enter your destination:- ";
        cin>>des;
        cout<<"Please enter the Weight of Edge:- ";
        cin>>weight;
        this->add_Edge(src,des,weight);
    }
}

template <class type1,class type2>
bool Graph<type1,type2>::DFS(type1 src,type1 des,vector<bool>&visited){
    if(src == des)return true;
    visited[src] = true;
    for(auto neighbour: weighted_Graph[src]){
        if(!visited[neighbour.first]){
            bool result = DFS(neighbour.first,des,visited);
            if(result)return true;
        }
    }
    return false;
}

template <class type1,class type2>
void Graph<type1,type2>::anyPath(type1 src,type1 des){
    vector<bool>visited(weighted_Graph.size(),false);
    bool flag = DFS(src,des,visited);
    if(flag)cout<<"Path Exists\n";
    else cout<<"Path does not exist\n";
}

template <class type1,class type2>
void Graph<type1,type2>::add_Edge(type1 src,type1 des,type2 weight){
    if(src<weighted_Graph.size() && des<weighted_Graph.size()){
        weighted_Graph[src].push_back({des,weight}); // Insert At End in Linked List
        weighted_Graph[des].push_back({src,weight}); // Insert At End in Linked List
    }
    else cout<<"Invalid Vertex Entered by You\n";
}

template<class type1,class type2>
void Graph<type1,type2>::display(){
    cout<<"Your Graph looks as Given Below:-\n";
    for(int i=0;i<weighted_Graph.size();i++){
        cout<<i<<" -> ";
        int size = weighted_Graph[i].size();
        for(auto ele: weighted_Graph[i]){
            if(size-1)cout<<"("<<ele.first<<","<<ele.second<<"),";
            else cout<<"("<<ele.first<<","<<ele.second<<")";
            size--;
        }
        cout<<endl;
    }
}

int main(){
    cout<<"\nWelcome to the world of programming\n";
    cout<<"Program is based on Weighted Graph DFS Traversal using Adjacency List approach and templates\n";
    cout<<"Here we check that there exists a path from source to destination or not\n";
    Graph<int,int> G;
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
        cout<<"Please enter your Destination:- ";
        cin>>des;
        G.anyPath(src,des);
    }
    return 0;
}