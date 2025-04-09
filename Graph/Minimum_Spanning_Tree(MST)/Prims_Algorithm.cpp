#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <set>
#include <unordered_map>
#include <climits>
using namespace std;

typedef pair<int,int> p;

class Graph{
    vector<list<p>>weighted_Graph;
public:
    Graph(){

    }
    Graph(int v){
        weighted_Graph.resize(v); // Resizing the Adjacency List
    }
    void createGraph();
    void add_Edge(int src,int des,int weight);
    void display();
    int primsAlgorithm(int src);
};

void Graph::createGraph(){
    int v,e; // v is the number of vertices and e is number of edges
    cout<<"Please Enter the Number of Vertices :- ";
    cin>>v;
    weighted_Graph.resize(v); // Resizing the Adjacency List
    cout<<"Please enter the number of edges in your graph:- ";
    cin>>e;
    while(e--){
        int src,des,weight;
        cout<<"Please enter your Source:- ";
        cin>>src;
        cout<<"Please enter your destination:- ";
        cin>>des;
        cout<<"Please enter the Weight of Edge:- ";
        cin>>weight;
        this->add_Edge(src,des,weight);
    }
}

void Graph::add_Edge(int src,int des,int weight){
    if(src<weighted_Graph.size() && des<weighted_Graph.size()){
        weighted_Graph[src].push_back({des,weight}); // Insert At End in Linked List
        weighted_Graph[des].push_back({src,weight}); // Insert At End in Linked List
    }
    else cout<<"Invalid Vertex Entered by You\n";
}

void Graph::display(){
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

int Graph::primsAlgorithm(int src){
    priority_queue<p,vector<p>,greater<p>>pq;
    set<int>visited;
    unordered_map<int,int>mp;
    for(int i=0;i<weighted_Graph.size();i++){
        mp[i] = INT_MAX;
    }
    int result = 0;
    int edges = weighted_Graph.size()-1;
    mp[src] = 0;
    pq.push({0,src});
    while(edges && !pq.empty()){
        p curr = pq.top();
        pq.pop();
        if(visited.count(curr.second)){
            continue;
        }
        visited.insert(curr.second);
        result += curr.first;
        for(auto neighbour: weighted_Graph[curr.second]){
            if(! visited.count(neighbour.first) && mp[neighbour.first] > neighbour.second){
                pq.push({neighbour.second,neighbour.first});
                mp[neighbour.first] = neighbour.second;
            }
        }
    }
    return result;
}

int main(){
    cout<<"Welcome to the World of Programming\n";
    cout<<"This Program is dedicated to Implement Prim's Algorithm\n";
    Graph G;
    G.createGraph();
    cout<<"Please enter the Source Node fro  where Prims Algorithm can start:- ";
    int src;
    cin>>src;
    cout<<"Minimum cost of the Spanning Tree of Your Graph by Prim's Algorithm:- "<<G.primsAlgorithm(src);
    return 0;
}