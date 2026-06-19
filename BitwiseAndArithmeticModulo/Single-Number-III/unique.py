from typing import List

class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        res = 0
        n = len(nums)
        for i in range(n):
            res ^= nums[i]
        k = 0
        while True:
            if res>>k & 1:
                break
            k += 1
        firstVal = 0
        for i in range(n):
            if nums[i] >> k & 1: firstVal ^= nums[i]
        secondVal = res ^ firstVal
        ans = [0]*2
        ans[0] = firstVal
        ans[1] = secondVal
        return ans