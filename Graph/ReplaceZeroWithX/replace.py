class Solution:
    def markAllRegion(self, board, r, c, p, x):
        m = len(board)
        n = len(board[0])

        if r < 0 or r >= m or c < 0 or c >= n:
            return
        elif board[r][c] == p:
            return
        elif board[r][c] == x:
            board[r][c] = p

            self.markAllRegion(board, r - 1, c, p, x)
            self.markAllRegion(board, r + 1, c, p, x)
            self.markAllRegion(board, r, c - 1, p, x)
            self.markAllRegion(board, r, c + 1, p, x)

    def fill(self, board):
        if not board:
            return

        m = len(board)
        n = len(board[0])

        # Traverse first and last column
        for i in range(m):
            if board[i][0] == 'O':
                self.markAllRegion(board, i, 0, '#', 'O')
            if board[i][n - 1] == 'O':
                self.markAllRegion(board, i, n - 1, '#', 'O')

        # Traverse first and last row
        for j in range(n):
            if board[0][j] == 'O':
                self.markAllRegion(board, 0, j, '#', 'O')
            if board[m - 1][j] == 'O':
                self.markAllRegion(board, m - 1, j, '#', 'O')

        # Final processing
        for i in range(m):
            for j in range(n):
                if board[i][j] == 'O':
                    board[i][j] = 'X'
                elif board[i][j] == '#':
                    board[i][j] = 'O'