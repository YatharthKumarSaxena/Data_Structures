class Solution:
    def zigZag(self,n) :
        if n==0: return
        print(n)
        self.zigZag(n-1)
        print(n)
        self.zigZag(n-1)
        print(n)
