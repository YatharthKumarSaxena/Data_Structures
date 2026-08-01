from collections import deque
from typing import List

class Solution:
    def countNodeInConnComp(self, visited, stones, node):
        qu = deque()
        qu.append(node)
        totalStones = len(stones)
        visited[node] = True
        while len(qu):
            currNode = qu.popleft()
            for neighbour in range(totalStones):
                if not visited[neighbour]:
                    # Same row OR same column
                    if (stones[currNode][0] == stones[neighbour][0] or
                        stones[currNode][1] == stones[neighbour][1]):

                        visited[neighbour] = True
                        qu.append(neighbour)
    def removeStones(self, stones: List[List[int]]) -> int:
        totalNodes = len(stones)
        totalComps = 0
        visited = [False] * totalNodes
        for i in range(totalNodes):
            if not visited[i]: 
                totalComps += 1
                self.countNodeInConnComp(visited,stones,i)
        return totalNodes-totalComps