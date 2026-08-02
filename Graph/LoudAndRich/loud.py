from typing import List
from collections import deque

class Solution:
    def loudAndRich(self, richer: List[List[int]], quiet: List[int]) -> List[int]:
        n = len(quiet)

        ans = [i for i in range(n)]
        adj = [[] for _ in range(n)]
        indegree = [0] * n

        for u, v in richer:
            adj[u].append(v)
            indegree[v] += 1

        qu = deque()

        for i in range(n):
            if indegree[i] == 0:
                qu.append(i)

        while qu:
            ele = qu.popleft()

            for neigh in adj[ele]:
                if quiet[ans[ele]] < quiet[ans[neigh]]:
                    ans[neigh] = ans[ele]

                indegree[neigh] -= 1
                if indegree[neigh] == 0:
                    qu.append(neigh)

        return ans