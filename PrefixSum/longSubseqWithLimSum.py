from typing import List

class Solution:
    def answerQueries(self, nums: List[int], queries: List[int]) -> List[int]:

        n = len(nums)
        m = len(queries)

        nums.sort()

        for i in range(1,n):
            nums[i]=nums[i-1]+nums[i]

        ans = [0]*m

        for i in range(m):
            target = queries[i]
            lo = 0
            hi = n-1
            while lo <= hi:
                mid = lo + (hi-lo)//2
                if nums[mid] <= target:
                    lo = mid+1
                else:
                    hi = mid-1
            ans[i]=hi + 1

        return ans