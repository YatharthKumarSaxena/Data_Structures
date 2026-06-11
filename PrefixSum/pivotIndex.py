from typing import List

class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        n = len(nums)
        for i in range(1,n):
            nums[i] = nums[i-1]+nums[i]
        idx = -1
        for i in range(n):
            leftVal = 0 if i==0 else nums[i-1]
            rightVal = nums[n-1]-nums[i]
            if leftVal == rightVal:
                idx = i
                break
        return idx