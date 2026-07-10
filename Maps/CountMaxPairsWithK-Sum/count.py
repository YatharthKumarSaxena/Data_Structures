from typing import List

class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        totalOps = 0
        mp = {}
        n = len(nums)
        for i in range(n):
            mp[nums[i]] = mp.get(nums[i],0) + 1
        for ele in mp:
            target = k - ele
            if ele == target:
                while mp[ele] > 1:
                    totalOps += 1
                    mp[ele] -= 2
            else:
                if target in mp and ele<target:
                    totalOps += min(mp[ele],mp[target])
        return totalOps
        