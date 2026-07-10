from typing import List
from collections import deque

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if k==1: return nums
        n = len(nums)
        dq = deque()
        ans = []
        for i in range(n):
            while len(dq) and nums[dq[-1]] < nums[i]: dq.pop()
            dq.append(i)
            j = i-k+1
            while len(dq) and dq[0] < j: dq.popleft()
            if i>=k-1: ans.append(nums[dq[0]])
        return ans

