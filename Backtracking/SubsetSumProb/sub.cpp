#include <bits/stdc++.h>
using namespace std;

class Solution1 {
  public:
    void doBacktrack(vector<int>& arr, vector<int> sample, int target, int idx, vector<vector<int>>& ans){
        int n = arr.size();
        if(idx == n){
            if(target==0){
                ans.push_back(sample);
            }
            return;
        }
        if(arr[idx]<=target){
            sample.push_back(arr[idx]);
            doBacktrack(arr,sample,target-arr[idx],idx+1,ans);
            sample.pop_back();
        }
        doBacktrack(arr,sample,target,idx+1,ans);
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        vector<int> sample;
        vector<vector<int>> ans;
        doBacktrack(arr,sample,sum,0,ans);
        if(ans.size())return true;
        return false;
    }
};


class Solution2 {
  public:
    bool doBacktrack(vector<int>& arr, vector<vector<int>>& dp, int target, int idx){
        int n = arr.size();
        if(idx == n){
            if(target==0){
                return true;
            }
            return false;
        }
        else if(dp[idx][target]!=-1)return dp[idx][target];
        bool take = false;
        if(arr[idx]<=target){
            take = doBacktrack(arr,dp,target-arr[idx],idx+1);
        }
        bool notTake = doBacktrack(arr,dp,target,idx+1);
        return dp[idx][target] = take || notTake;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        for(int i=0;i<n;i++){
            dp[i][0] = 1;
        }
        return doBacktrack(arr,dp,sum,0);
    }
};