class Solution:
    def countWays(self, n):
        # code here
        if n==0: return 1
        if n < 0: return 0
        return self.countWays(n-1) + self.countWays(n-2)