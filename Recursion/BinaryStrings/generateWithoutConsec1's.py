# User function Template for python3
class Solution:

    def countStrings(self, n):
        # code here
        if n == 1:
            return 2

        a = 2
        b = 3
        c = 0

        for i in range(3, n + 1):
            c = a + b
            a = b
            b = c

        return b
