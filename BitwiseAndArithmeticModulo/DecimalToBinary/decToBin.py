class Solution:
    def decToBinary(self, n):
        # code here
        ans = ""
        while n>0:
            rem = n%2
            ans += chr(rem+48)
            n //= 2
        ans = ans[::-1]
        return ans