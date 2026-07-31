from collections import deque

class Solution:
    def isCyclic(self, V, edges):
        indegree = [0] * V
        adj = [[] for _ in range(V)]

        # Build graph
        for u, v in edges:
            adj[u].append(v)
            indegree[v] += 1

        # Push all vertices with indegree 0
        q = deque()
        for i in range(V):
            if indegree[i] == 0:
                q.append(i)

        # Kahn's Algorithm
        while q:
            node = q.popleft()

            for neighbour in adj[node]:
                indegree[neighbour] -= 1
                if indegree[neighbour] == 0:
                    q.append(neighbour)

        # If any vertex still has indegree > 0, cycle exists
        for i in range(V):
            if indegree[i] != 0:
                return True

        return False