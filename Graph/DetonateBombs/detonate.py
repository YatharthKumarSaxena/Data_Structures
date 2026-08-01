from collections import deque

class Solution:
    def findMaxBombExplode(self, bombs, start):
        n = len(bombs)

        maxBombs = 0
        visited = [False] * n

        qu = deque()
        qu.append(start)
        visited[start] = True

        while qu:
            idx = qu.popleft()
            maxBombs += 1

            for j in range(n):
                if not visited[j]:
                    dx = bombs[idx][0] - bombs[j][0]
                    dy = bombs[idx][1] - bombs[j][1]
                    r = bombs[idx][2]

                    if dx * dx + dy * dy <= r * r:
                        qu.append(j)
                        visited[j] = True

        return maxBombs

    def maximumDetonation(self, bombs):
        maxBombs = 1
        n = len(bombs)

        for i in range(n):
            maxBombs = max(maxBombs, self.findMaxBombExplode(bombs, i))

        return maxBombs