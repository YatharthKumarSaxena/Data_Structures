class Solution:
    def isPowerofTwo(self, n):
        # code here
        if n <= 0: return False
        while n > 1:
            if n%2 != 0: return False
            n /= 2
        return True