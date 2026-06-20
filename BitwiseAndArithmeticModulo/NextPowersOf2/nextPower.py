class Solution:
    def nextPowerOfTwo(self, n):
        #code here
        ans = n
        count = 0
        while n:
            ans = n
            n &= (n-1)
            count += 1
        if count > 1: ans *= 2
        return ans