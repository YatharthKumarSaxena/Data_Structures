#User function Template for python3

class Solution:
    def flipBits(self, N):
        # code here
        mask = 2**32-1
        val = N^mask
        ans = [""]*2
        ans[0] += str(val)
        while val:
            rem = val%2
            ans[1] += chr(rem+48)
            val //= 2
        return ans