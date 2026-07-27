from collections import deque

class Solution:
    def bfs(self, adj):
        # code here
        ans = []
        qu = deque()
        n = len(adj)
        visited = [False] * n
        qu.append(0)
        
        while len(qu):
            
            ele = qu.popleft()
            if visited[ele]: continue
            visited[ele] = True
            ans.append(ele)
            for neighbour in adj[ele]:
                if not visited[neighbour]: qu.append(neighbour)
            
        return ans
        