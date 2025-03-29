#include <iostream>
#include <list>
#include <unordered_set>
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
    void DFS(type1 src,type1 des,unordered_set<type1>&visited,vector<type1>&path,vector<vector<type1>>&totalPath);
    void allPath(type1 src,type1 des);
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
void Graph<type1,type2>::DFS(type1 src,type1 des,unordered_set<type1>&visited,vector<type1>&path,vector<vector<type1>>&totalPath){
    if(src == des){
        path.push_back(des);
        totalPath.push_back(path);
        path.pop_back();
        return;
    }
    visited.insert(src);
    path.push_back(src);
    for(auto neighbour: weighted_Graph[src]){
        if(not visited.count(neighbour.first)){
            DFS(neighbour.first,des,visited,path,totalPath);
        }
    }
    visited.erase(src);
    path.pop_back();
    return;
}

template <class type1,class type2>
void Graph<type1,type2>::allPath(type1 src,type1 des){
    vector<type1>path;
    unordered_set<type1>visited;
    vector<vector<type1>>totalPath;
    DFS(src,des,visited,path,totalPath);
    cout<<"All paths are displayed below from Vertex "<<src<<" to "<<des<<":-\n";
    for(int i=0;i<totalPath.size();i++){
        int n = totalPath[i].size();
        for(int j=0;j<n;j++){
            if(j<n-1)cout<<totalPath[i][j]<<" -> ";
            else cout<<totalPath[i][j];
        }
        cout<<endl;
    }
    return;
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
    cout<<"Here we check all possible paths from source to destination or not\n";
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
        G.allPath(src,des);
    }
    return 0;
}