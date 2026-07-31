class Solution:
    def checkCycleByDFS(self, currNode, parent, graph, visited):
        visited[currNode] = True
        for neighbour in graph[currNode]:
            if not visited[neighbour]:
                if self.checkCycleByDFS(neighbour, currNode, graph, visited):
                    return True
            elif neighbour != parent:
                return True
        return False 
        
    def isCycle(self, V, edges):
        #Code here
        visited = [False] * V
        adjList = [[] for _ in range(V)]
        totalEdges = len(edges)
        for i in range(totalEdges):
            adjList[edges[i][0]].append(edges[i][1])
            adjList[edges[i][1]].append(edges[i][0])
        for i in range(V):
            if not visited[i]:
                if self.checkCycleByDFS(i, -1, adjList, visited):
                    return True
        return False