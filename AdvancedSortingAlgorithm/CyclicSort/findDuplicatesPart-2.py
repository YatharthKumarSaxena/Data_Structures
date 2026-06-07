from typing import List

class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        n = len(nums)
        i = 0
        while i < n:
            correctedIdx = nums[i]-1
            if nums[i] == i+1 or nums[i] == nums[correctedIdx]:
                i += 1
            else:
                nums[i],nums[correctedIdx] = nums[correctedIdx],nums[i]
        ans = []
        for i in range(n):
            if nums[i] != i+1:
                ans.append(nums[i])
        return ans
        