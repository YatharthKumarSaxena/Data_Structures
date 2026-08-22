class Solution:

    def checkInSafeState(self, board, r, c):
        n = len(board)

        # Column
        for i in range(n):
            if board[i][c] == 'Q':
                return False

        # Row
        for j in range(n):
            if board[r][j] == 'Q':
                return False

        # Upper-left diagonal
        i, j = r, c
        while i >= 0 and j >= 0:
            if board[i][j] == 'Q':
                return False
            i -= 1
            j -= 1

        # Upper-right diagonal
        i, j = r, c
        while i >= 0 and j < n:
            if board[i][j] == 'Q':
                return False
            i -= 1
            j += 1

        return True

    def doBacktrack(self, ans, board, r):
        n = len(board)

        if r == n:
            helper = []

            for i in range(n):
                temp = ""

                for j in range(n):
                    temp += board[i][j]

                helper.append(temp)

            ans.append(helper)
            return

        for c in range(n):

            if self.checkInSafeState(board, r, c):

                board[r][c] = 'Q'

                self.doBacktrack(ans, board, r + 1)

                # Backtrack
                board[r][c] = '.'

    def solveNQueens(self, n):
        board = [['.' for _ in range(n)] for _ in range(n)]

        ans = []

        self.doBacktrack(ans, board, 0)

        return ans