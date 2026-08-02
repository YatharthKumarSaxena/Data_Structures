#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int>findInNodes(vector<vector<int>>& graph,vector<int>& outdegree){
        int n = graph.size();
        vector<int>ans;
        queue<int>qu;

        for (int i = 0; i < n; i++) {
            if (outdegree[i] == 0)
                qu.push(i);
        }

        while(!qu.empty()){
            int ele = qu.front();
            ans.push_back(ele);
            qu.pop();
            for(int neigh: graph[ele]){
                outdegree[neigh]--;
                if(outdegree[neigh]==0){
                    qu.push(neigh);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>adj(n,vector<int>());
        vector<int> outdegree(n);
        for(int i=0;i<n;i++){
            outdegree[i] = graph[i].size();
            for(int neigh: graph[i]){
                adj[neigh].push_back(i);
            }
        }
        vector<int>ans = findInNodes(adj,outdegree);
        return ans;
    }
};