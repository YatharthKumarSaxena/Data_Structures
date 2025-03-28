// Not Much Used
#include <iostream>
#include <vector>
using namespace std;

template <class type>
class Vertex{
    type data;
};

template <class type1,class type2>
class Edge{
    Vertex src;
    Vertex des;
    bool biDir;
    type2 weight;
};

template <class type1,class type2>
class Graph{
    vector<Vertex>Vertices;
    vector<Edge>Edges;
};

