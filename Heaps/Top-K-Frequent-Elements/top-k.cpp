#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    typedef pair<int,int> pip;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        priority_queue<pip,vector<pip>,greater<pip>>pq;
        for(auto p: mp){
            int freq = p.second;
            int ele = p.first;
            pq.push({freq,ele});
            if(pq.size()>k)pq.pop();
        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};