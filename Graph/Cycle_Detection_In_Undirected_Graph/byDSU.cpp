#include <iostream>
#include <vector>
#include <set>
#include <list>
using namespace std;

class DSU{
    int capacity;
    int *par;
    int *rank;
public:
    DSU(int capacity){
        this->capacity = capacity;
        par = new int[capacity];
        rank = new int[capacity];
        for(int i=0;i<capacity;i++){
            rank[i] = 1;
            par[i] = i;
        }
    }
    void unionOfGroups(int eleA,int eleB);
    int findGroupLeader(int ele);
};

int DSU::findGroupLeader(int ele){
    return par[ele] = ((par[ele]==ele)?ele:findGroupLeader(par[ele]));
}

void DSU::unionOfGroups(int eleA,int eleB){
    int parA = findGroupLeader(eleA);
    int parB = findGroupLeader(eleB);
    if(parA == parB)return;
    if(rank[parA]>=rank[parB]){
        par[parB] = parA;
        rank[parA]++;
    }
    else{
        par[parA] = parB;
        rank[parB]++;
    }
}

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

void Graph::has_Cycle(){
    set<pair<int,int>>visited;
    DSU dsu(unweighted_Graph.size());
    for(int i=0;i<unweighted_Graph.size();i++){
        for(auto neighbour:unweighted_Graph[i]){
            if(!visited.count({i,neighbour}) && !visited.count({neighbour,i})){
                if(dsu.findGroupLeader(i)!=dsu.findGroupLeader(neighbour)){
                    dsu.unionOfGroups(i,neighbour);
                }
                else{
                    cout<<"Cycle Detected\n";
                    return;
                }
                visited.insert({i,neighbour});
            }
        }
    }
    cout<<"No Cycle Exists\n";
    return;
}

int main(){
    cout<<"\nWelcome to the world of programming\n";
    cout<<"Program is dedicated to detect a Cycle in Undirected Graph using DSU\n";
    Graph G;
    G.createGraph();
    G.has_Cycle();
}