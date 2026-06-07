from typing import List

class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = []
        i = 0
        while i<n:
            if nums[i] == i+1: i += 1
            else:
                correctedIdx = nums[i]-1
                if nums[i] == nums[correctedIdx]:
                    i += 1
                else:
                    nums[i],nums[correctedIdx] = nums[correctedIdx],nums[i]
        for i in range(n):
            if i+1 != nums[i]:
                ans.append(i+1)
        return ans
