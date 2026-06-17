from typing import List

class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        # code here 
        n = len(nums)
        sum = 0
        currLen = 0
        minLen = float('inf')
        i = 0
        j = 0
        while j<n:
            sum += nums[j]
            while sum >= target:
                currLen = j-i+1
                minLen = min(minLen,currLen)
                sum -= nums[i]
                i += 1
            j += 1
        return minLen if minLen != float('inf') else 0  