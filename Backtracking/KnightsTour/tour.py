class Solution:
    def __init__(self):
        self.dir = [1, -1, 1, -1, 2, -2, 2, -2]
        self.dic = [2, 2, -2, -2, 1, 1, -1, -1]

    def checkIsInSafeState(self, ans, i, j, n):
        if 0 <= i < n and 0 <= j < n and ans[i][j] == -1:
            return True
        return False

    def doBacktrack(self, count, ans, i, j, n):
        if count == n * n - 1:
            return True

        for k in range(8):
            r = i + self.dir[k]
            c = j + self.dic[k]

            if self.checkIsInSafeState(ans, r, c, n):
                ans[r][c] = count + 1

                if self.doBacktrack(count + 1, ans, r, c, n):
                    return True

                ans[r][c] = -1

        return False

    def knightTour(self, n):
        ans = [[-1] * n for _ in range(n)]

        ans[0][0] = 0

        if self.doBacktrack(0, ans, 0, 0, n):
            return ans

        return []