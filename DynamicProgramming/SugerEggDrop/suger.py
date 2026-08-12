class Solution:
    def superEggDrop(self, k: int, n: int) -> int:
        dp = [[0 for _ in range(n+1)] for _ in range(k+1)]
        for moves in range(1,n+1):
            for eggs in range(1,k+1):
                dp[eggs][moves] = dp[eggs-1][moves-1] + dp[eggs][moves-1] + 1
                if dp[eggs][moves] >= n:
                    return moves
        return n