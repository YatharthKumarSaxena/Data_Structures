class Solution:
    def minSteps(self, n: int) -> int:
        ans = 0
        i = 2
        while n>1:
            while n%i==0:
                ans += i
                n /= i
            i += 1
        return ans