#include <iostream>
#include <set>
#include <queue>
#include <list>
#include <vector>
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
    void topologicalBFS();
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

void Graph::topologicalBFS(){
    int v = this->unweighted_Graph.size();  // Number of Vertices
    // Making Indegree Array
    vector<int>indegreeArray(v,0);
    for(int i=0;i<v;i++){
        for(auto neighbour: unweighted_Graph[i]){
            // i -------> neighbour
            indegreeArray[neighbour]++;
        }
    }
    // Preparing Essentialities for Kahn's Algorithm
    queue<int>qu;
    set<int>visited;
    for(int i=0;i<v;i++){
        if(indegreeArray[i]==0){
            qu.push(i); // Making Queue
            visited.insert(i); // Making Set
        }
    }
    // Applying Topological Sort
    while(! qu.empty()){
        int ele = qu.front();
        cout<<ele<<" ";
        qu.pop();
        for(auto neighbour: unweighted_Graph[ele]){
            // Helps in Detecting the Cycle Since One Element can be visited only Once time
            if(! visited.count(neighbour)){
                indegreeArray[neighbour]--;
                if(indegreeArray[neighbour]==0){
                    qu.push(neighbour);
                    visited.insert(neighbour);
                }
            }
        }
    }
    cout<<endl;
}

void Graph::add_Edge(int src,int des){ // Graph is Directed
    if(src<unweighted_Graph.size() && des<unweighted_Graph.size()){
        unweighted_Graph[src].push_back(des); // Insert At End in Linked List
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
int main(){
    cout<<"Welcome to the World of Programming\n";
    cout<<"This Program is dedicated to find the Topological Sort of a graph\n";
    Graph G;
    G.createGraph();
    G.topologicalBFS();
    return 0;
}