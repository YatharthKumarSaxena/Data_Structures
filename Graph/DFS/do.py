class Solution:
    def doDFS(self, adj, ans, visited, node):
        visited[node] = True
        ans.append(node)

        for neighbour in adj[node]:
            if not visited[neighbour]:
                self.doDFS(adj, ans, visited, neighbour)

    def dfs(self, adj):
        visited = [False] * len(adj)
        ans = []

        self.doDFS(adj, ans, visited, 0)

        return ans