from typing import List

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        n = len(nums)
        mazorityEle = nums[0]
        appearCount = 1
        for i in range(n):
            if nums[i]!=mazorityEle:
                appearCount-=1
                if appearCount == 0:
                    mazorityEle = nums[i]
                    appearCount+=1
            else: appearCount+=1
        return mazorityEle