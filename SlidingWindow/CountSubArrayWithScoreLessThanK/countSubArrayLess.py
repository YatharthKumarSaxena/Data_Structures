from typing import List

class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        if k<=1: return 0
        n = len(nums)
        ans = 0
        i = 0
        j = 0
        winSum = 0
        score = 0
        while j<n:
            winSum += nums[j]
            score = winSum * (j-i+1)
            while score >= k:
                winSum -= nums[i]
                i += 1
                score = winSum * (j-i+1)
            ans += (j-i+1)
            j += 1
        return ans
