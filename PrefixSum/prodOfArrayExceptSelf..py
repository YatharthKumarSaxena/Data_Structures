from typing import List

class Solution1:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        allEleProd = 1
        noOfZeros = 0
        for i in range(n):
            if nums[i] == 0:
                noOfZeros += 1
            else:
                allEleProd *= nums[i]
        if noOfZeros > 1:
            nums[:] = [0] * n
        else:
            for i in range(n):
                if nums[i] != 0 and noOfZeros == 0: nums[i] = allEleProd//nums[i]
                elif nums[i] == 0: nums[i] = allEleProd
                else: nums[i] = 0
        return nums
         
class Solution2:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        pre = [0]*n
        suf = [0]*n
        ans = [0]*n
        prodVar = 1
        for i in range(n):
            pre[i] = prodVar
            prodVar *= nums[i]
        prodVar = 1
        for i in range(n-1,-1,-1):
            suf[i] = prodVar
            prodVar *= nums[i]
        for i in range(n):
            ans[i] = pre[i] * suf[i]
        return ans
