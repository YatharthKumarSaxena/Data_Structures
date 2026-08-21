class Solution:
    def doBacktrack(self, maze, ans, i, j, path):
        n = len(maze)

        if i == n - 1 and j == n - 1:
            ans.append(path)
            return

        if i < 0 or i >= n or j < 0 or j >= n:
            return

        if maze[i][j] == 0 or maze[i][j] == 2:
            return

        maze[i][j] = 2

        self.doBacktrack(maze, ans, i + 1, j, path + 'D')
        self.doBacktrack(maze, ans, i - 1, j, path + 'U')
        self.doBacktrack(maze, ans, i, j - 1, path + 'L')
        self.doBacktrack(maze, ans, i, j + 1, path + 'R')

        maze[i][j] = 1

    def ratInMaze(self, maze):
        n = len(maze)

        if maze[n - 1][n - 1] == 0 or maze[0][0] == 0:
            return []

        ans = []

        self.doBacktrack(maze, ans, 0, 0, "")

        ans.sort()

        return ans