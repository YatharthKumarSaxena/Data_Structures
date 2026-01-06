from typing import List

class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        r = len(matrix)
        c = len(matrix[0])
        count = r*c
        minr = 0
        maxr = r-1
        minc = 0
        maxc = c-1
        ans = [0]*count
        tne = r*c
        while count>0:
            for i in range(minc,maxc+1):
                if not count: break
                ans[tne-count] = matrix[minr][i]
                count -= 1
            minr += 1
            for i in range(minr,maxr+1):
                if not count: break
                ans[tne-count] = matrix[i][maxc]
                count -= 1
            maxc -= 1
            for i in range(maxc,minc-1,-1):
                if not count: break
                ans[tne-count] = matrix[maxr][i]
                count -= 1
            maxr -= 1
            for i in range(maxr,minr-1,-1):
                if not count: break
                ans[tne-count] = matrix[i][minc]
                count -= 1
            minc += 1
        return ans