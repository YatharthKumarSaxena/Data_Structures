#include <vector>
#include <unordered_map>
#include <cmath>
#include <queue>
using namespace std;

class Solution {
public:
    typedef pair<int,int> pip;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int dis = pow(points[i][0],2) + pow(points[i][1],2);
            mp[i] = dis;
        }
        priority_queue<pip>pq;
        for(auto p: mp){
            int dis = p.second;
            int idx = p.first;
            pq.push({dis,idx});
            if(pq.size()>k)pq.pop();
        }
        vector<vector<int>>ans;
        while(!pq.empty()){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};