class Solution:

    def solve(self, i, count, n, visited, adjList):

        if count == n:
            return True

        for curr in adjList[i]:

            if not visited[curr]:

                visited[curr] = True

                if self.solve(
                    curr,
                    count + 1,
                    n,
                    visited,
                    adjList
                ):
                    return True

                # Backtrack
                visited[curr] = False

        return False

    def check(self, n, m, edges):

        adjList = [[] for _ in range(n + 1)]

        # Build adjacency list
        for i in range(m):
            u = edges[i][0]
            v = edges[i][1]

            adjList[u].append(v)
            adjList[v].append(u)

        # Try every vertex as starting point
        for start in range(1, n + 1):

            visited = [False] * (n + 1)

            visited[start] = True

            if self.solve(
                start,
                1,
                n,
                visited,
                adjList
            ):
                return True

        return False