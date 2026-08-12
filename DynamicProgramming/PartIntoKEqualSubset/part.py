from typing import List

class Solution:
    def doDP(self, mask, k, target, currSum, nums, dp):
        if k==1: return True
        elif dp[mask] != -1: return dp[mask]
        elif currSum == target:
            dp[mask] = self.doDP(mask,k-1,target,0,nums,dp)
            return dp[mask]
        n = len(nums)
        for i in range(n):
            if mask & (1<<i): continue
            elif currSum + nums[i] > target: continue
            elif self.doDP(mask | (1<<i), k, target, currSum + nums[i], nums, dp):
                dp[mask] = 1
                return True
        dp[mask] = 0
        return False
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        overallSum = 0
        n = len(nums)
        for i in range(n):
            overallSum += nums[i]
        if overallSum%k != 0: return False
        target = overallSum//k
        totComb = 1<<n
        dp = [-1 for _ in range(totComb)]
        return self.doDP(0,k,target,0,nums,dp)