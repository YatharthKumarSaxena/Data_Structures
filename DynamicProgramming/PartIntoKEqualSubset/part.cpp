#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    bool doDP(vector<int>& nums, int k, vector<int>& dp, int mask, int target, int currSum){
        if(k==1)return true;
        else if(dp[mask]!=-1)return dp[mask];
        else if(currSum==target){
            return dp[mask] = doDP(nums,k-1,dp,mask,target,0);
        }
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(mask & 1<<i)continue;
            else if(currSum+nums[i]>target)continue;
            else if(doDP(nums,k,dp,mask | (1<<i), target, currSum+nums[i]))
            return dp[mask] = 1;
        }
        return dp[mask] = 0;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int tot = accumulate(nums.begin(),nums.end(),0);
        if(tot%k!=0)return false;
        int target = tot/k;
        int n = nums.size();
        vector<int>dp(1<<n,-1);
        return doDP(nums,k,dp,0,target,0);
    }
};