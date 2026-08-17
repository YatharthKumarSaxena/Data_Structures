class Solution:
    def checkInSafeState(self, board, r, c, val):
        # Column
        for i in range(9):
            if board[i][c] == val:
                return False

        # Row
        for j in range(9):
            if board[r][j] == val:
                return False

        # 3x3 Box
        sr = (r // 3) * 3
        sc = (c // 3) * 3

        for i in range(sr, sr + 3):
            for j in range(sc, sc + 3):
                if board[i][j] == val:
                    return False

        return True

    def solveBack(self, board, r, c):
        if r == 9:
            return True

        elif c == 9:
            return self.solveBack(board, r + 1, 0)

        elif board[r][c] != '.':
            return self.solveBack(board, r, c + 1)

        for j in range(9):
            val = chr(ord('1') + j)

            if self.checkInSafeState(board, r, c, val):
                board[r][c] = val

                if self.solveBack(board, r, c + 1):
                    return True

                board[r][c] = '.'

        return False

    def solveSudoku(self, board):
        self.solveBack(board, 0, 0)