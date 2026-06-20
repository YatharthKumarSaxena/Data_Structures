from math import sqrt

class Solution:
    def getDivisors(self, n):
        # code here
        ans = []
        for i in range(1,int(sqrt(n))+1):
            if n%i==0:
                ans.append(i)

        for i in range(int(sqrt(n)),0,-1):
            if n%i==0:
                if n//i != i: ans.append(n//i)
                
        return ans;