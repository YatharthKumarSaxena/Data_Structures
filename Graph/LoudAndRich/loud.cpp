#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<int>ans(n,0);
        vector<vector<int>>adj(n,vector<int>());
        vector<int> indegree(n);
        int totalDep = richer.size();
        for(int i=0;i<totalDep;i++){
            int u = richer[i][0];
            int v = richer[i][1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        for (int i = 0; i < n; i++) ans[i] = i;
        queue<int>qu;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)qu.push(i);
        }
        while(!qu.empty()){
            int ele = qu.front();
            qu.pop();
            for(int neigh: adj[ele]){
                if (quiet[ans[ele]] < quiet[ans[neigh]]) {
                    ans[neigh] = ans[ele];
                }
                indegree[neigh]--;
                if(indegree[neigh]==0)qu.push(neigh);
            }
        }
        return ans;
    }
};


