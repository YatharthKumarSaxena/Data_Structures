from typing import List

class Solution:
    def doDFS(self, node, target, path, graph, ans):
        path.append(node)
        if node==target:
            ans.append(path.copy())
            path.pop()
            return
        for neighbour in graph[node]:
            self.doDFS(neighbour, target, path, graph, ans)
        path.pop()

    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        n = len(graph)
        ans = []
        self.doDFS(0,n-1,[],graph,ans)
        return ans