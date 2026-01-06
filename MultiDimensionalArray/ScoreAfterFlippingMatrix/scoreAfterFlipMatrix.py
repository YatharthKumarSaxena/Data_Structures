from typing import List

class Solution:
    def matrixScore(self, grid: List[List[int]]) -> int:
        rows = len(grid)
        cols = len(grid[0])
        for i in range(rows):
            if not grid[i][0]:
                for j in range(cols):
                    if grid[i][j]: grid[i][j] = 0
                    else: grid[i][j] = 1
        for j in range(cols):
            noz = 0
            for i in range(rows):
                if not grid[i][j]: noz += 1
            if noz > (rows - noz):
                for i in range(rows):
                    if grid[i][j]: grid[i][j] = 0
                    else: grid[i][j] = 1
        ans = 0
        for i in range(rows):
            value = 0
            mul = 1
            for j in range(cols-1,-1,-1):
                value += (grid[i][j]*mul)
                mul *= 2
            ans += value
        return ans            
        