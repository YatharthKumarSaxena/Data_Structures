from collections import deque

class Solution:
    def colorByBFS(self, adjList, start, color):
        color[start] = 0
        qu = deque()
        qu.append(start)
        while len(qu):
            curr = qu.popleft()
            for neighbour in adjList[curr]:
                if color[neighbour] == -1:
                    color[neighbour] = 1-color[curr]
                    qu.append(neighbour)
                elif color[neighbour] == color[curr]: return False
        return True
        
    def isBipartite(self, V, edges):
        # code here
        color = [-1] * V
        adjList = [[] for _ in range(V)]
        totalEdges = len(edges)
        for i in range(totalEdges):
            u = edges[i][0]
            v = edges[i][1]
            adjList[u].append(v)
            adjList[v].append(u)
        for i in range(V):
            if color[i]==-1:
                if not self.colorByBFS(adjList,i,color): return False
                
        return True