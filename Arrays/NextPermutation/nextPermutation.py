from typing import List

class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        idx = -1
        for i in range(n-2,-1,-1):
            if nums[i]<nums[i+1] :
                idx = i
                break
        if idx == -1:
            nums.reverse()
        else:
            nums[idx+1:] = sorted(nums[idx+1:])
            swapIdx = idx+1
            while swapIdx < n:
                if nums[idx] < nums[swapIdx]:
                    break
                swapIdx += 1
            nums[idx], nums[swapIdx] = nums[swapIdx], nums[idx]        