from collections import deque

class Solution:
    def minStepToReachTarget(self, knightPos, targetPos, n):
        #Code here
        visited = [[False] * n for _ in range(n)]
        qu = deque()
        
        knightPos = [knightPos[0]-1,knightPos[1]-1]
        targetPos = [targetPos[0]-1,targetPos[1]-1]
        
        if knightPos == targetPos: return 0
        
        qu.append(((knightPos[0],knightPos[1]),0))
        visited[knightPos[0]][knightPos[1]] = True
        
        while len(qu):
            (currPos,moves) = qu.popleft()
            if [currPos[0],currPos[1]] == targetPos: return moves
            row = currPos[0]
            col = currPos[1]
            if row-2 >= 0 and col-1>=0 and not visited[row-2][col-1]:
                visited[row-2][col-1] = True
                qu.append(((row-2,col-1),moves+1))
            if row-2 >= 0 and col+1<n and not visited[row-2][col+1]: 
                visited[row-2][col+1] = True       
                qu.append(((row-2,col+1),moves+1))
            if row+2 < n and col-1>=0 and not visited[row+2][col-1]:
                visited[row+2][col-1] = True                
                qu.append(((row+2,col-1),moves+1))
            if row+2 < n and col+1<n and not visited[row+2][col+1]:
                visited[row+2][col+1] = True         
                qu.append(((row+2,col+1),moves+1))
            if row-1 >= 0 and col-2 >= 0 and not visited[row-1][col-2]:
                visited[row-1][col-2] = True          
                qu.append(((row-1, col-2), moves+1))
            if row+1 < n and col-2 >= 0 and not visited[row+1][col-2]:
                visited[row+1][col-2] = True 
                qu.append(((row+1, col-2), moves+1))
            if row-1 >= 0 and col+2 < n and not visited[row-1][col+2]:
                visited[row-1][col+2] = True
                qu.append(((row-1, col+2), moves+1))
            if row+1 < n and col+2 < n and not visited[row+1][col+2]:
                visited[row+1][col+2] = True
                qu.append(((row+1, col+2), moves+1))
        return -1