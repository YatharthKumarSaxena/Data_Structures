MOD = 10**9 + 7

n = int(input())

dp = [0] * (n + 1)
dp[0] = 1

for i in range(1, n + 1):
    for dice in range(1, 7):
        if i >= dice:
            dp[i] = (dp[i] + dp[i - dice]) % MOD

print(dp[n])