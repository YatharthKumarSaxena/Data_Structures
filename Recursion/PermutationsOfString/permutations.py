#User function Template for python3

class Solution:
    def findPermutations(self, ans, s, start):
        if start == len(s) - 1:
            ans.append("".join(s))
            return

        used = [False] * 26

        for i in range(start, len(s)):
            idx = ord(s[i]) - 65

            if used[idx]:
                continue

            used[idx] = True

            s[start], s[i] = s[i], s[start]
            self.findPermutations(ans, s, start + 1)
            s[start], s[i] = s[i], s[start]
            
    def findPermutation(self, s):
        # Code here
        s = list(s)
        s.sort()
        if len(s)==0: return []
        ans = []
        self.findPermutations(ans, s, 0)
        return ans
        
