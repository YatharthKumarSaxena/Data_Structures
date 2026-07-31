#include <vector>
using namespace std;

class Solution {
  public:
    int findParent(int a,vector<int>& parent){
        if(parent[a] == a)return a;
        return parent[a] = findParent(parent[a],parent);
    }
    void unionGroup(int a, int b, vector<int>& parent){
        int parB = findParent(b,parent);
        int parA = findParent(a,parent);
        parent[parA] = parB;
        return;
    }
    vector<int> DSU(int n, vector<vector<int>>& queries) {
        // code here
        vector<int>parent(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
        vector<int>ans;
        int querySize = queries.size();
        for(int i=0;i<querySize;i++){
            if(queries[i][0]==2)ans.push_back(findParent(queries[i][1],parent));
            else unionGroup(queries[i][1],queries[i][2],parent);
        }
        return ans;
    }
};