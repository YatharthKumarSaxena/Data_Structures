class Solution:

    def __init__(self):
        self.dp = []
        self.groupScore = []

    def solve(self, mask, n):

        if mask == (1 << n) - 1:
            return 0

        if self.dp[mask] != -1:
            return self.dp[mask]

        ans = float('-inf')

        remaining = ((1 << n) - 1) ^ mask

        sub = remaining

        while sub:
            ans = max(
                ans,
                self.groupScore[sub] +
                self.solve(mask | sub, n)
            )

            sub = (sub - 1) & remaining

        self.dp[mask] = ans
        return ans

    def maxScore(self, a):

        n = len(a)

        self.dp = [-1] * (1 << n)
        self.groupScore = [0] * (1 << n)

        for mask in range(1 << n):

            for i in range(n):

                if mask & (1 << i):

                    for j in range(i + 1, n):

                        if mask & (1 << j):
                            self.groupScore[mask] += a[i][j]

        return self.solve(0, n)