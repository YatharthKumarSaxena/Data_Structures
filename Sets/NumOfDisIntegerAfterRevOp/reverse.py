from typing import List

class Solution:
    def countDistinctIntegers(self, nums: List[int]) -> int:
        n = len(nums)
        for i in range(n):
            revDigit = int(str(nums[i])[::-1])
            nums.append(revDigit)
        ans = set()
        for i in range(2*n):
            ans.add(nums[i])
        return len(ans)