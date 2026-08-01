#include <vector>
#include <algorithm>
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
        int rankA = rank[a];
        int rankB = rank[b];
        if(parA == parB)return false;
        if(rankA >= rankB){
            parent[parB] = parA;
            rank[parA]++;
        }else{
            parent[parA] = parB;
            rank[parB]++;
        }
        return true;
    }
    static bool cmp(vector<int>& a, vector<int> & b){
        return a[2]<b[2];
    }
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        sort(edges.begin(),edges.end(),cmp);
        vector<int> parent(V);
        vector<int>rank(V,1);
        for(int i=0;i<V;i++){
            parent[i] = i;
        }
        int ans = 0;
        int totalEdges = edges.size();
        int allowedEdges = 0;
        int i=0;
        while(allowedEdges < V-1){
            if(unionGroup(edges[i][0],edges[i][1],parent,rank)){
                allowedEdges++;
                ans += edges[i][2];
            }
            i++;
        }
        return ans;
    }
};