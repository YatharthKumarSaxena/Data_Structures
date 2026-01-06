class Solution:
    def computeFactorial(self, n):
        ans = 1
        for i in range(1, n + 1):
            ans *= i
        return ans

    def computeCombination(self, n, r):
        return self.computeFactorial(n) // (
            self.computeFactorial(n - r) * self.computeFactorial(r)
        )

    def nthRowOfPascalTriangle(self, n):
        l = [0] * n
        for i in range(n):
            l[i] = self.computeCombination(n - 1, i)
        return l
