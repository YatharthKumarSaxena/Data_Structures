# User function Template for python3
class Solution:
    def setBits(self, n):
        # code here
        ans = 0
        while n > 0:
            ans += 1
            n &= (n - 1)
        return ans