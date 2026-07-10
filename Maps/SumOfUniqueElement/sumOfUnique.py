from typing import List

class Solution:
    def sumOfUnique(self, nums: List[int]) -> int:
        mp = {}
        n = len(nums)
        for i in range(n):
            mp[nums[i]] = mp.get(nums[i],0) + 1
        ans = 0
        for ele in mp:
            if mp[ele] == 1: ans += ele
        return ans