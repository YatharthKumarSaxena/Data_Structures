#include <vector>
using namespace std;

class Solution {
public:
    int findMaxRob(vector<int>& nums, vector<int>& dp, int idx){
        if(idx == 0)return nums[idx];
        else if(idx == 1)return max(nums[idx],nums[idx-1]);
        else if(dp[idx]!=-1)return dp[idx];
        return dp[idx] = max(findMaxRob(nums,dp,idx-1),nums[idx]+findMaxRob(nums,dp,idx-2));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        dp[0] = nums[0];
        return findMaxRob(nums,dp,n-1);
    }
};