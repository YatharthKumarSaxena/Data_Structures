from typing import List

class Solution:
    def reverseDigit(self, n):
        return int(str(n)[::-1])
    def countNicePairs(self, arr: List[int]) -> int:
        n = len(arr)
        for i in range(n):
            arr[i] -= self.reverseDigit(arr[i])
        count = 0
        mp = {}
        for i in range(n):
            count = count%1000000007
            if arr[i] in mp:
                count += mp[arr[i]]
            mp[arr[i]] = mp.get(arr[i],0) + 1
        return count%1000000007