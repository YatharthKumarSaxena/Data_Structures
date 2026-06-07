from typing import List

class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        n = len(nums)
        i = 0
        while i < n:
            correctedIdx = nums[i]
            if nums[i] == nums[correctedIdx]: return correctedIdx
            else: nums[i],nums[correctedIdx] = nums[correctedIdx],nums[i]
        return -1