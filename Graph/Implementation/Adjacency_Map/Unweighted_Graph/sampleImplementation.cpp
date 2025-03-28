#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Graph{
    vector<unordered_map<int,int>>weightedGraph;
public:
    Graph(){

    }
    Graph(int v){
        weightedGraph.resize(v,unordered_map<int,int>());
    }
    void createGraph();
    void addEdge(int src,int des,int weight,bool dir);
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
    weightedGraph.resize(v,unordered_map<int,int>());
    while(e--){
        int src,des,weight;
        cout<<"Please enter the Source:- ";
        cin>>src;
        cout<<"Please enter the Destination:- ";
        cin>>des;
        cout<<"Please enter the weight of the Edge:- ";
        cin>>weight;
        this->addEdge(src,des,weight,dir);
    }
}

void Graph::addEdge(int src,int des,int weight,bool dir){
    if(src<weightedGraph.size() && des<weightedGraph.size()){
        weightedGraph[src][des] = weight;
        if(dir){
            weightedGraph[des][src] = weight;
        }
    }
    else{
        cout<<"Invalid Source and destination enetered by you\n";
    }
}

void Graph::display(){
    cout<<"Your Graph looks as given Below:- \n";
    int size = weightedGraph.size();
    for(int i=0;i<size;i++){
        cout<<i<<" -> ";
        int n = weightedGraph[i].size();
        for(auto ele: weightedGraph[i]){
            if(n-1)cout<<"("<<ele.first<<","<<ele.second<<"),";
            else cout<<"("<<ele.first<<","<<ele.second<<")";
            n -= 1;
        }
        cout<<endl;
    }
}

int main(){
    cout<<"\nWelcome to the world of programming\n";
    cout<<"This Program is based on Weighted Graph Implementation using Adjacency Map approach\n";
    Graph G;
    G.createGraph();
    G.display();
    return 0;
}