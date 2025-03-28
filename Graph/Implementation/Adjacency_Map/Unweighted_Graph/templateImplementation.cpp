#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

template <class type1,class type2>
class Graph{
    vector<unordered_map<type1,type2>>weightedGraph;
public:
    Graph(){

    }
    Graph(int v){
        weightedGraph.resize(v,unordered_map<type1,type2>());
    }
    void createGraph();
    void addEdge(type1 src,type1 des,type2 weight,bool bidir);
    void display();
};

template <class type1,class type2>
void Graph<type1,type2>::createGraph(){
    int v,e;
    cout<<"Please enter the Number of Vertex in your Graph:- ";
    cin>>v;
    cout<<"Please enter the Number of Edges in your Graph:- ";
    cin>>e;
    bool bidir;
    cout<<"Do you want to make your Graph Bidirected if yes press 1 otherwise 0:- ";
    cin>>bidir;
    weightedGraph.resize(v,unordered_map<type1,type2>());
    while(e--){
        type1 src,des;
        type2 weight;
        cout<<"Please enter the Source:- ";
        cin>>src;
        cout<<"Please enter the Destination:- ";
        cin>>des;
        cout<<"Please enter the weight of the Edge:- ";
        cin>>weight;
        this->addEdge(src,des,weight,bidir);
    }
}

template <class type1,class type2>
void Graph<type1,type2>::addEdge(type1 src,type1 des,type2 weight,bool bidir){
    if(src<weightedGraph.size() && des<weightedGraph.size()){
        weightedGraph[src][des] = weight;
        if(bidir){
            weightedGraph[des][src] = weight;
        }
    }
    else{
        cout<<"Invalid Source and destination enetered by you\n";
    }
}

template <class type1,class type2>
void Graph<type1,type2>::display(){
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
    cout<<"This Program is based on Weighted Graph Implementation using Adjacency Map approach with templates\n";
    Graph<int,int> G;
    G.createGraph();
    G.display();
    return 0;
}