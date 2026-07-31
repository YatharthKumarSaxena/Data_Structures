from collections import deque

class Solution:
    def checkCycleByBFS(self, currNode, parent, graph, visited):
        qu = deque()
        qu.append(currNode)
        visited[currNode] = True

        while qu:
            ele = qu.popleft()

            for neighbour in graph[ele]:
                if not visited[neighbour]:
                    visited[neighbour] = True
                    parent[neighbour] = ele
                    qu.append(neighbour)

                elif neighbour != parent[ele]:
                    return True

        return False

    def isCycle(self, V, edges):
        visited = [False] * V
        parent = [-1] * V
        adjList = [[] for _ in range(V)]

        for u, v in edges:
            adjList[u].append(v)
            adjList[v].append(u)

        for i in range(V):
            if not visited[i]:
                if self.checkCycleByBFS(i, parent, adjList, visited):
                    return True

        return False