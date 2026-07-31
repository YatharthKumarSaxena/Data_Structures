from collections import deque

class Solution:
    def findOrder(self, n, prerequisites):
        # code here 
        adj = [[] for _ in range(n)]
        ans = []
        dependencies = len(prerequisites)
        for i in range(dependencies):
            adj[prerequisites[i][1]].append(prerequisites[i][0])
        indegrees = [0]*n
        for i in range(dependencies):
            indegrees[prerequisites[i][0]]+=1
        qu = deque()
        for i in range(n):
            if indegrees[i]==0: qu.append(i)
        while len(qu):
            ele = qu.popleft()
            ans.append(ele)
            for neighbour in adj[ele]:
                indegrees[neighbour] -= 1
                if indegrees[neighbour] == 0: qu.append(neighbour)
        for i in range(n):
            if indegrees[i] != 0: return []
        return ans
