#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void doBackTrack(vector<vector<int>>& ans, int idx,vector<int>& nums){
        int n = nums.size();
        if(idx==n){
            ans.push_back(nums);
            return;
        }
        unordered_set<int>st;
        for(int i=idx;i<n;i++){
            if(st.count(nums[i]))continue;
            st.insert(nums[i]);
            swap(nums[i],nums[idx]);
            doBackTrack(ans,idx+1,nums);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        doBackTrack(ans,0,nums);
        return ans;
    }
};