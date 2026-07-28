from collections import deque

class Solution:
    def nearest(self, mat):
        m = len(mat)
        n = len(mat[0])

        dis = [[-1] * n for _ in range(m)]
        qu = deque()

        # Push all 1's into the queue
        for i in range(m):
            for j in range(n):
                if mat[i][j]:
                    qu.append(((i, j), 0))
                    dis[i][j] = 0

        while qu:
            (row, col), dist = qu.popleft()
            newDist = dist + 1

            if row > 0 and mat[row - 1][col] == 0 and dis[row - 1][col] == -1:
                dis[row - 1][col] = newDist
                qu.append(((row - 1, col), newDist))

            if row < m - 1 and mat[row + 1][col] == 0 and dis[row + 1][col] == -1:
                dis[row + 1][col] = newDist
                qu.append(((row + 1, col), newDist))

            if col < n - 1 and mat[row][col + 1] == 0 and dis[row][col + 1] == -1:
                dis[row][col + 1] = newDist
                qu.append(((row, col + 1), newDist))

            if col > 0 and mat[row][col - 1] == 0 and dis[row][col - 1] == -1:
                dis[row][col - 1] = newDist
                qu.append(((row, col - 1), newDist))

        return dis