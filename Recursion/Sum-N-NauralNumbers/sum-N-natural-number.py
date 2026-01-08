class Solution:
    def findSum(self, n):
        # code here
        if n==0: return 0
        return n+self.findSum(n-1)
        
