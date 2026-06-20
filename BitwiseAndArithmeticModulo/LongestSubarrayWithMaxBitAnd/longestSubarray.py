from typing import List

class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        ans = 0
        count = 0
        maxEle = -float('inf')
        n = len(nums)
        for i in range(n):
            if nums[i]>maxEle:
                maxEle = nums[i]
                ans = 1
                count = 1
            elif nums[i]==maxEle:
                count += 1
            else:
                count = 0
            ans = max(ans,count)
        return ans