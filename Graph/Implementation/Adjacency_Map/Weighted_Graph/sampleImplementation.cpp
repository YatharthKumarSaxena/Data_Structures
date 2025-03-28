#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Graph{
    vector<unordered_set<int>>unweightedGraph;
public:
    Graph(){

    }
    Graph(int v){
        unweightedGraph.resize(v,unordered_set<int>());
    }
    void createGraph();
    void addEdge(int src,int des,bool dir);
    void display();
};

void Graph::createGraph(){
    int v,e;
    cout<<"Please enter the Number of Vertex in your Graph:- ";
    cin>>v;
    cout<<"Please enter the Number of Edges in your Graph:- ";
    cin>>e;
    bool dir;
    cout<<"Do you want to make your Graph Bidirected if yes press 1 otherwise 0:- ";
    cin>>dir;
    unweightedGraph.resize(v,unordered_set<int>());
    while(e--){
        int src,des;
        cout<<"Please enter the Source:- ";
        cin>>src;
        cout<<"Please enter the Destination:- ";
        cin>>des;
        this->addEdge(src,des,dir);
    }
}

void Graph::addEdge(int src,int des,bool dir){
    if(src<unweightedGraph.size() && des<unweightedGraph.size()){
        unweightedGraph[src].insert(des);
        if(dir){
            unweightedGraph[des].insert(src);
        }
    }
    else{
        cout<<"Invalid Source and destination entered by you\n";
    }
}

void Graph::display(){
    cout<<"Your Graph looks as given Below:- \n";
    int size = unweightedGraph.size();
    for(int i=0;i<size;i++){
        cout<<i<<" -> ";
        int n = unweightedGraph[i].size();
        for(auto ele: unweightedGraph[i]){
            if(n-1)cout<<ele<<",";
            else cout<<ele;
            n -= 1;
        }
        cout<<endl;
    }
}

int main(){
    cout<<"\nWelcome to the world of programming\n";
    cout<<"This Program is based on Unweighted Graph Implementation using Adjacency Set approach\n";
    Graph G;
    G.createGraph();
    G.display();
    return 0;
}