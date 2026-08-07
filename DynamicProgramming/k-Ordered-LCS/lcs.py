class Solution:
    def kOrderedLCS(self, i, j, k, seq1, seq2, dp):
        n = len(seq1)
        m = len(seq2)

        if i == n or j == m:
            return 0

        if dp[i][j][k] != -1:
            return dp[i][j][k]

        res = 0

        if seq1[i] == seq2[j]:
            res = 1 + self.kOrderedLCS(i + 1, j + 1, k, seq1, seq2, dp)
        else:
            if k > 0:
                res = max(
                    res,
                    1 + self.kOrderedLCS(i + 1, j + 1, k - 1, seq1, seq2, dp)
                )

            res = max(res, self.kOrderedLCS(i + 1, j, k, seq1, seq2, dp))
            res = max(res, self.kOrderedLCS(i, j + 1, k, seq1, seq2, dp))

        dp[i][j][k] = res
        return res


N, M, K = map(int, input().split())

seq1 = list(map(int, input().split()))
seq2 = list(map(int, input().split()))

dp = [[[-1 for _ in range(K + 1)] for _ in range(M + 1)] for _ in range(N + 1)]

obj = Solution()
print(obj.kOrderedLCS(0, 0, K, seq1, seq2, dp))