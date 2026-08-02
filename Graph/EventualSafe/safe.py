from collections import deque
from typing import List

class Solution:
    def findInNodes(self, graph, outdegree):
        n = len(graph)

        ans = []
        qu = deque()

        for i in range(n):
            if outdegree[i] == 0:
                qu.append(i)

        while qu:
            ele = qu.popleft()
            ans.append(ele)

            for neigh in graph[ele]:
                outdegree[neigh] -= 1

                if outdegree[neigh] == 0:
                    qu.append(neigh)

        ans.sort()
        return ans

    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        n = len(graph)

        adj = [[] for _ in range(n)]
        outdegree = [0] * n

        for i in range(n):
            outdegree[i] = len(graph[i])

            for neigh in graph[i]:
                adj[neigh].append(i)

        return self.findInNodes(adj, outdegree)