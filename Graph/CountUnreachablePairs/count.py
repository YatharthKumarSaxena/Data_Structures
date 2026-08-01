from collections import deque
from typing import List

class Solution:
    def countNodeInConnComp(self, visited, adjList, node):
        qu = deque()
        qu.append(node)
        totalNodes = 0
        visited[node] = True
        while len(qu):
            currNode = qu.popleft()
            totalNodes += 1
            for neighbour in adjList[currNode]:
                if not visited[neighbour]:
                    qu.append(neighbour)
                    visited[neighbour] = True
        return totalNodes

    def countPairs(self, n: int, edges: List[List[int]]) -> int:
        adjList = [[] for _ in range(n)]
        visited = [False] * n
        totalEdges = len(edges)
        for i in range(totalEdges):
            adjList[edges[i][0]].append(edges[i][1])
            adjList[edges[i][1]].append(edges[i][0])
        totalNodeInComps = []
        for i in range(n):
            if not visited[i]: 
                totalNodeInComps.append(self.countNodeInConnComp(visited,adjList,i))
        totalComps = len(totalNodeInComps)
        if totalComps==1: return 0
        suffixSum = [0] * totalComps
        totalComp = 0
        for i in range(totalComps-1,-1,-1):
            suffixSum[i] = totalComp
            totalComp += totalNodeInComps[i]
        totalUnreachablePairs = 0
        for i in range(totalComps):
            totalUnreachablePairs += (suffixSum[i]*totalNodeInComps[i])
        return totalUnreachablePairs