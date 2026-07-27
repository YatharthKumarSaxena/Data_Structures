from typing import List

class Solution:
    def doDFS(self,grid,visited,roomNum):
        if not visited[roomNum]:
            visited[roomNum] = True
        for neighbour in grid[roomNum]:
            if not visited[neighbour]: self.doDFS(grid,visited,neighbour)
        return
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        n = len(rooms)
        if n == 0: return True
        visited = [False]*n
        self.doDFS(rooms,visited,0)
        for i in range(n):
            if not visited[i]: return False
        return True