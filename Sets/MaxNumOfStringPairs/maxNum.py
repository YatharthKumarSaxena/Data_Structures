from typing import List

class Solution:
    def maximumNumberOfStringPairs(self, words: List[str]) -> int:
        st = set()
        n = len(words)
        ans = 0
        for i in range(n):
            checkStr = words[i][::-1]
            if checkStr!=words[i]:
                if checkStr not in st: st.add(words[i])
                else: ans+=1
        return ans