#include <vector>
using namespace std;

class Solution {
  public:
    int findParent(int a,vector<int>& parent){
        if(parent[a] == a)return a;
        return parent[a] = findParent(parent[a],parent);
    }
    bool unionGroup(int a, int b, vector<int>& parent, vector<int>& rank){
        int parB = findParent(b,parent);
        int parA = findParent(a,parent);
        if(parA==parB)return false;
        int rankA = rank[a];
        int rankB = rank[b];
        if(rankA >= rankB){
            parent[parB] = parA;
            rankA++;
        }else{
            parent[parA] = parB;
            rankB++;
        }
        return true;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int>parent(V,0);
        vector<int>rank(V,1);
        for(int i=0;i<V;i++){
            parent[i] = i;
        }
        int totalEdges = edges.size();
        for(int i=0;i<totalEdges;i++){
            if(!unionGroup(edges[i][0],edges[i][1],parent,rank))return true;
        }
        return false;
    }
};