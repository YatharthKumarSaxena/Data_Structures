import sys

input = sys.stdin.readline

def solve():
    n, x = map(int, input().split())
    coins = list(map(int, input().split()))

    INF = 10**9
    dp = [INF] * (x + 1)

    dp[0] = 0

    for i in range(x + 1):
        for coin in coins:
            if i >= coin and dp[i - coin] != INF:
                dp[i] = min(dp[i], dp[i - coin] + 1)

    if dp[x] == INF:
        print(-1)
    else:
        print(dp[x])

if __name__ == "__main__":
    solve()