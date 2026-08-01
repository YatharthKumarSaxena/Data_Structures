from collections import deque

class Solution:
    def floodFill(self, image, sr, sc, newColor):
        m = len(image)
        n = len(image[0])

        qu = deque()
        visited = [[False] * n for _ in range(m)]

        qu.append((sr, sc))
        origColor = image[sr][sc]
        image[sr][sc] = newColor
        visited[sr][sc] = True

        dx = [-1, 0, 1, 0]
        dy = [0, -1, 0, 1]

        while qu:
            r, c = qu.popleft()

            for i in range(4):
                nr = r + dx[i]
                nc = c + dy[i]

                if 0 <= nr < m and 0 <= nc < n:
                    if (not visited[nr][nc] and
                        image[nr][nc] == origColor):

                        qu.append((nr, nc))
                        image[nr][nc] = newColor
                        visited[nr][nc] = True

        return image