from typing import List

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        rows = len(matrix)
        cols = len(matrix[0])
        i=0
        j=cols-1
        while i<rows and i>=0 and j>=0 and j<cols:
            if matrix[i][j] == target: return True
            elif matrix[i][j] > target : 
                j-=1
            else:
                i+=1
        return False