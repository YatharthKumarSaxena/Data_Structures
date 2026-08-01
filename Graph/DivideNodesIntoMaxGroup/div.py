from collections import deque

class Solution:
    def colorByBFS(self, adjList, start, color):
        color[start] = 0

        qu = deque([start])
        component = []

        while qu:
            node = qu.popleft()
            component.append(node)

            for neighbour in adjList[node]:
                if color[neighbour] == -1:
                    color[neighbour] = 1 - color[node]
                    qu.append(neighbour)
                elif color[neighbour] == color[node]:
                    return []

        return component

    def bfsLevels(self, adjList, start):
        n = len(adjList)

        visited = [False] * n
        visited[start] = True

        qu = deque([(start, 1)])
        maxLevel = 1

        while qu:
            node, level = qu.popleft()
            maxLevel = max(maxLevel, level)

            for neighbour in adjList[node]:
                if not visited[neighbour]:
                    visited[neighbour] = True
                    qu.append((neighbour, level + 1))

        return maxLevel

    def magnificentSets(self, n, edges):
        color = [-1] * n
        adjList = [[] for _ in range(n)]

        for u, v in edges:
            u -= 1
            v -= 1
            adjList[u].append(v)
            adjList[v].append(u)

        comps = []

        for i in range(n):
            if color[i] == -1:
                component = self.colorByBFS(adjList, i, color)

                if not component:
                    return -1

                comps.append(component)

        ans = 0

        for component in comps:
            best = 0

            for node in component:
                best = max(best, self.bfsLevels(adjList, node))

            ans += best

        return ans