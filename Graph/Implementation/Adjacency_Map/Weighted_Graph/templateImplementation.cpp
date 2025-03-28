#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

template <class type>
class Graph{
    vector<unordered_set<type>>unweightedGraph;
public:
    Graph(){

    }
    Graph(int v){
        unweightedGraph.resize(v,unordered_set<type>());
    }
    void createGraph();
    void addEdge(type src,type des,bool dir);
    void display();
};

template <class type>
void Graph<type>::createGraph(){
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
        type src,des;
        cout<<"Please enter the Source:- ";
        cin>>src;
        cout<<"Please enter the Destination:- ";
        cin>>des;
        this->addEdge(src,des,dir);
    }
}

template <class type>
void Graph<type>::addEdge(type src,type des,bool dir){
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

template <class type>
void Graph<type>::display(){
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
    Graph<int> G;
    G.createGraph();
    G.display();
    return 0;
}