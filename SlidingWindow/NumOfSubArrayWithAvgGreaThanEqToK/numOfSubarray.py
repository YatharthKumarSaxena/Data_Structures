from typing import List

class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        n = len(arr)
        if k>n: return 0
        winSum = 0
        for i in range(k):
            winSum += arr[i]
        i = 0
        j = k
        ans = 0
        while j < n:
            winAvg = winSum // k
            if winAvg >= threshold: ans += 1
            winSum = (winSum - arr[i] + arr[j])
            i += 1
            j += 1
        if winSum//k >= threshold: ans += 1
        return ans
