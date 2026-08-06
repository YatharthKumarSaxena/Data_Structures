import sys

input = sys.stdin.readline

def find_digits(num):
    digits = []
    while num:
        digits.append(num % 10)
        num //= 10
    return digits

def solve():
    n = int(input())

    INF = float('inf')
    dp = [INF] * (n + 1)

    dp[0] = 0

    for i in range(1, min(10, n + 1)):
        dp[i] = 1

    for i in range(10, n + 1):
        digits = find_digits(i)
        for d in digits:
            if d != 0 and dp[i - d] != INF:
                dp[i] = min(dp[i], dp[i - d] + 1)

    print(dp[n])

if __name__ == "__main__":
    solve()