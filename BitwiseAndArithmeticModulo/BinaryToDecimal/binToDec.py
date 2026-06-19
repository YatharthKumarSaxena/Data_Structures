class Solution:
    def binaryToDecimal(self, b):
        # code here
        n = len(b)
        ans = 0
        base = 1

        for i in range(n - 1, -1, -1):
            ans += base * (ord(b[i]) - 48)
            base *= 2

        return ans