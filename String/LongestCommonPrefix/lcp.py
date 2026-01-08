from typing import List

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        strs.sort()
        n = len(strs)
        t = 0
        for i in range(min(len(strs[0]),len(strs[n-1]))):
            if strs[0][i] != strs[n-1][i]: 
                break
            else: t += 1
        return strs[0][0:t]

        