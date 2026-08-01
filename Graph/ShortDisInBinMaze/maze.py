from collections import deque

class Solution:
    def shortestPath(self, mat: list[list[int]], src: list[int], dest: list[int]) -> int:
        # code here
        m = len(mat)
        n = len(mat[0])

        qu = deque()
        
        sr = src[0]
        sc = src[1]
        
        fr = dest[0]
        fc = dest[1]
        
        if not mat[sr][sc] or not mat[fr][fc]: return -1
        if not (0 <= sr < m and 0 <= sc < n): return -1
        if not (0 <= fr < m and 0 <= fc < n): return -1
        
        visited = [[False for _ in range(n)] for _ in range(m)]
        
        qu.append(((sr, sc),0))
        visited[sr][sc] = True

        dx = [-1, 0, 1, 0]
        dy = [0, -1, 0, 1]

        while qu:
            curr = qu.popleft()
            r = curr[0][0]
            c = curr[0][1]
            dis = curr[1]
            
            if (r,c) == (fr,fc): return dis

            for i in range(4):
                nr = r + dx[i]
                nc = c + dy[i]

                if 0 <= nr < m and 0 <= nc < n:
                    if not visited[nr][nc] and mat[nr][nc]:
                        qu.append(((nr, nc),dis+1))
                        visited[nr][nc] = True

        return -1