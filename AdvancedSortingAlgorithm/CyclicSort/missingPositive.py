from typing import List

class Solution1:
    def firstMissingPositive(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        ans = 1
        for i in range(n):
            if nums[i] <= 0: continue
            else:
                if nums[i]==ans: ans += 1
                elif nums[i]<ans: continue
                else: return ans
        return ans
    


class Solution2(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        i = 0
        while i<n:
            if nums[i]<=0 or nums[i]>n: i += 1
            else:
                correctedIdx = nums[i]-1
                if nums[i] == i+1 or nums[i] == nums[correctedIdx]: i += 1
                else: nums[i],nums[correctedIdx] = nums[correctedIdx],nums[i]
        for i in range(n):
            if nums[i] != i+1:
                return i+1
        return n+1