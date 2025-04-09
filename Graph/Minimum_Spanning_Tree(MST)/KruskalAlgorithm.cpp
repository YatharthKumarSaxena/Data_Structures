#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

class DSU{
    // Data Members
    int *par; // Parent Array
    int *rank; // Size of the Parent Array
    int capacity;
public:
    // Parameterized Constructor
    DSU(int capacity){
        this->capacity = capacity;
        this->par = new int[capacity];
        this->rank = new int[capacity];
        for(int i=0;i<capacity;i++){
            par[i]=i;
            rank[i]=1; // Each Element is Linked To Itself , So there is one Direct Link
        }
    }
    // Member Functions
    int findGroupLeader(int ele);
    void unionGroups(int eleA,int eleB);
    int getRank(int ele);
    int getSize();
};

// Path Compression
int DSU::findGroupLeader(int ele){ // Return the Group Element of the Element ele present in a group
    return par[ele] = ((ele == par[ele])?ele:findGroupLeader(par[ele]));
}
void DSU::unionGroups(int eleA,int eleB){ // Combine the Group Elements of B into Group Elements of A
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
    return;
}
int DSU::getSize(){ // Return the Size of the Disjoint Set Union
    return this->capacity;
}
int DSU::getRank(int ele){ // Return the Rank of the Element
    return this->rank[ele];
}

class Edge{
public:
    int source;
    int destination;
    int weight;
    Edge(int source,int destination,int weight){
        this->source = source;
        this->destination = destination;
        this->weight = weight;
    }
    Edge() {
        source = destination = weight = 0;
    }
};

class Graph{
    // Data Members
    int vertices; // Total Number of Vertices
    vector<Edge>graph;
public:
    // Default Constructor
    Graph(){

    }
    // Parameterized Constructor
    Graph(int totalVertices,int totalEdges){
        this->vertices = totalVertices;
        this->graph.resize(totalEdges);
    }
    // Member Functions
    void createGraph();
    void add_Edge(int source,int destination,int weight);
    int kruskalAlgorithm();
};

void Graph::add_Edge(int source,int destination,int weight){
    Edge e(source,destination,weight);
    graph.push_back(e);
}

void Graph::createGraph(){
    int v,e;
    cout<<"Please enter the number of vertices in your Graph:- ";
    cin>>v;
    cout<<"Please enter the total number of edges in your Graph:- ";
    cin>>e;
    this->vertices = v;
    while(e--){
        int s,d,w; // Source, Destination , Weight
        cout<<"Please enter the Source:- ";
        cin>>s;
        cout<<"Please enter the destination:- ";
        cin>>d;
        cout<<"Please enter the Weight of the Edge:- ";
        cin>>w;
        this->add_Edge(s,d,w);
    }
}

int Graph::kruskalAlgorithm(){
    int cost = 0;
    sort(graph.begin(), graph.end(), [](const Edge &a, const Edge &b){
        return a.weight < b.weight;
    });
    int e = this->vertices-1; // MST Number of Edges
    DSU dsu(this->vertices+1);
    int c=0;
    while(e){
        if(c>=graph.size()){
            cout<<"Kruskal Algorithm not applicable as Graph is Disconnected\n";
            break;
        }
        int v1 = graph[c].source;
        int v2 = graph[c].destination;
        int par1 = dsu.findGroupLeader(v1);
        int par2 = dsu.findGroupLeader(v2);
        if(par1!=par2){
            dsu.unionGroups(v1,v2);
            cost += graph[c].weight;
            e--;
        }
        c++;
    }
    return cost;
}

int main(){
    cout<<"Welcome to the World of Programming\n";
    cout<<"This Program is dedicated to Implement Kruskal Algorithm\n";
    Graph G;
    G.createGraph();
    cout<<"Minimum cost of the Spanning Tree of Your Graph by Kruskal Algorithm:- "<<G.kruskalAlgorithm();
    return 0;
}