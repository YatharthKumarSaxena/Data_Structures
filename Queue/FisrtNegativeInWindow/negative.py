from collections import deque

class Solution:
    def firstNegInt(self, arr, k): 
         # code here 
        qu = deque()
        n = len(arr)
        for i in range(n):
            if arr[i]<0:
                qu.append(i)
        ans = [0] * (n-k+1)
        for i in range(n-k+1):
            winSize = i+k
            while(len(qu)):
                idx = qu[0]
                if idx < winSize and idx>=i:
                    ans[i] = arr[idx]
                    break
                else: 
                    if idx<i: qu.popleft()
                    else: break
        return ans
                