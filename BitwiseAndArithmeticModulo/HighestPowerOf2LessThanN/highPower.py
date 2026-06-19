#User function Template for python3
class Solution1:
    def nthPosition (self, n):
        # code here 
        iterations = 6
        base = 1
        for i in range(1,iterations+1):
            rightShiftVal = n>>base
            base *= 2
            n |= rightShiftVal
        return (n+1)//2
    
#User function Template for python3
class Solution2:
    def nthPosition (self, n):
        # code here 
        ans = n
        while n>0:
            ans = n
            n &= n-1
        return ans