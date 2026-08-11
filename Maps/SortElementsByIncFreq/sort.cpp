#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<int,int> pip;
    struct Compare{
        bool operator()(const pip& a, const pip& b){
            if(a.first != b.first){
                return a.first>b.first;
            }
            return a.second < b.second;
        }
    };
    vector<int> frequencySort(vector<int>& nums) {
        priority_queue<pip, vector<pip>, Compare> pq;
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto Pair: mp){
            int ele = Pair.first;
            int count = Pair.second;
            pq.push({count,ele});
        }
        vector<int>ans;
        while(pq.size()){
            pip Pair = pq.top();
            pq.pop();
            int ele = Pair.second;
            while(mp[ele]){
                ans.push_back(ele);
                mp[ele]--;
            }
            mp.erase(ele);
        }
        return ans;
    }
};