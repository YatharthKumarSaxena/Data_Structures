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
    unordered_map<int,int> bellmanFordAlgorithm(int src);
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

unordered_map<int,int> Graph::bellmanFordAlgorithm(int src){
    int V = weighted_Graph.size();
    unordered_map<int,int> dist;
    for(int i = 0; i < V; ++i){
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    // Step 1: Relax all edges (V-1) times
    for(int i = 0; i < V - 1; ++i){
        for(int u = 0; u < V; ++u){
            for(auto edge : weighted_Graph[u]){
                int v = edge.first;
                int wt = edge.second;
                if(dist[u] != INT_MAX && dist[v] > dist[u] + wt){
                    dist[v] = dist[u] + wt;
                }
            }
        }
    }

    // Step 2: Check for negative weight cycles
    for(int u = 0; u < V; ++u){
        for(auto edge : weighted_Graph[u]){
            int v = edge.first;
            int wt = edge.second;
            if(dist[u] != INT_MAX && dist[v] > dist[u] + wt){
                cout<<"Graph contains a negative weight cycle!\n";
                return {}; // Empty map to indicate failure
            }
        }
    }

    return dist;
}

int main(){
    cout<<"Welcome to the World of Programming\n";
    cout<<"This Program is dedicated to Implement BellmanFord Algorithm\n";
    Graph G;
    G.createGraph();
    cout<<"Please enter the Source Node from  where BellmanFord Algorithm can start:- ";
    int src;
    cin>>src;
    cout<<"Minimum shotest distance from the Source "<<src<<" to \n";
    unordered_map<int,int> sp = G.bellmanFordAlgorithm(src);
    for(auto ele: sp){
        cout<<ele.first<<" --> "<<ele.second;
        cout<<endl;
    }
    return 0;
}