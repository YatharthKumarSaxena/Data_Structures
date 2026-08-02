from collections import deque

class Solution:
    def calcLengthOfCycle(self, currNode, adjList, V):
        qu = deque()
        visited = [False] * V
        parent = [-1] * V
        visited[currNode] = True
        dist = [-1] * V
        dist[currNode] = 0
        ans = float('inf')
        qu.append(currNode)
        while len(qu):
            ele = qu.popleft()
            for neighbour in adjList[ele]:
                if not visited[neighbour]:
                    visited[neighbour] = True
                    parent[neighbour] = ele
                    dist[neighbour] = dist[ele]+1
                    qu.append(neighbour)
                elif neighbour != parent[ele]:
                    ans = min(ans,dist[ele]+dist[neighbour]+1)
        return ans if ans != float('inf') else -1            
        
    def shortCycle(self, V, edges):
        # code here
        adjList = [[] for _ in range(V)]
        totalEdges = len(edges)
        for i in range(totalEdges):
            u = edges[i][0]
            v = edges[i][1]
            adjList[u].append(v)
            adjList[v].append(u)
        ans = float('inf')
        for i in range(V):
            res = self.calcLengthOfCycle(i,adjList,V)
            if res != -1: ans = min(ans,res)
        return ans if ans != float('inf') else -1 
        