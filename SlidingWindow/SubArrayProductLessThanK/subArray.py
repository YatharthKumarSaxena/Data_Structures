from typing import List

class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        if k<=1: return 0
        i = 0
        j = 0
        ans = 0
        product = 1
        n = len(nums)
        while j < n:
            product *= nums[j]
            while product >= k:
                ans += (j-i)
                product //= nums[i]
                i += 1
            j += 1
        while i<n:
            ans += (j-i)
            product //= nums[i]
            i += 1
        return ans
        