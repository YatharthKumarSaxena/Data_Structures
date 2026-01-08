class Solution:
    def fact(self, n: int) -> int:
        if n==0 or n==1: return 1
        return n*self.fact(n-1)