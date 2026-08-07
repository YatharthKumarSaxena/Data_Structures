from functools import lru_cache

def calcRockWin(r, s, p):
    @lru_cache(None)
    def dfs(r, s, p):
        if s == 0 or r == 0:
            return 0.0
        elif p == 0:
            return 1.0

        total = r * s + s * p + p * r

        prs = (r * s) / total
        psp = (s * p) / total
        ppr = (p * r) / total

        return (
            prs * dfs(r, s - 1, p) +
            psp * dfs(r, s, p - 1) +
            ppr * dfs(r - 1, s, p)
        )

    return dfs(r, s, p)


def calcSciWin(r, s, p):
    @lru_cache(None)
    def dfs(r, s, p):
        if s == 0 or p == 0:
            return 0.0
        elif r == 0:
            return 1.0

        total = r * s + s * p + p * r

        prs = (r * s) / total
        psp = (s * p) / total
        ppr = (p * r) / total

        return (
            prs * dfs(r, s - 1, p) +
            psp * dfs(r, s, p - 1) +
            ppr * dfs(r - 1, s, p)
        )

    return dfs(r, s, p)


def calcPapWin(r, s, p):
    @lru_cache(None)
    def dfs(r, s, p):
        if r == 0 or p == 0:
            return 0.0
        elif s == 0:
            return 1.0

        total = r * s + s * p + p * r

        prs = (r * s) / total
        psp = (s * p) / total
        ppr = (p * r) / total

        return (
            prs * dfs(r, s - 1, p) +
            psp * dfs(r, s, p - 1) +
            ppr * dfs(r - 1, s, p)
        )

    return dfs(r, s, p)


r, s, p = map(int, input().split())

res1 = calcRockWin(r, s, p)
res2 = calcSciWin(r, s, p)
res3 = calcPapWin(r, s, p)

print(f"{res1:.12f} {res2:.12f} {res3:.12f}")