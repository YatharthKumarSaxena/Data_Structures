from typing import List

class Solution:
    def singleNumber(self, nums: List[int]) -> int:

        n = len(nums)
        ans = [0]*32

        for k in range(32):
            for i in range(n):
                if nums[i]>>k & 1: ans[k]+=1


        for k in range(32):
            ans[k] = ans[k]%3

        finalVal = 0
        base = 1

        for k in range(32):
            finalVal += base*ans[k]
            base *= 2

        if finalVal >= 2**31: finalVal -= 2**32
        
        return finalVal
