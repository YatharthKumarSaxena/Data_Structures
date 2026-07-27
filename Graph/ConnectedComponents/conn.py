class Solution:
    def doDFS(self, adj, visited, node):
        if visited[node]:
            return

        visited[node] = True

        for neighbour in adj[node]:
            if not visited[neighbour]:
                self.doDFS(adj, visited, neighbour)

    def countConnected(self, n, edges):
        adj = [[] for _ in range(n)]

        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        visited = [False] * n
        totalCC = 0

        for i in range(n):
            if not visited[i]:
                totalCC += 1
                self.doDFS(adj, visited, i)

        return totalCC