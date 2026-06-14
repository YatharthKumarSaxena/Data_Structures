from typing import List

class Solution:
    def findPrefixScore(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [0]*n
        for i in range(n):
            ans[i] = nums[i] if i==0 else max(nums[i],ans[i-1])
        for i in range(n):
            ans[i] += nums[i]
        for i in range(1,n):
            ans[i] += ans[i-1]
        return ans