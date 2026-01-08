import sys

class Solution:
    def findMax(self,arr,idx):
        if len(arr) == idx: return sys.maxsize* -1
        return max(arr[idx],self.findMax(arr,idx+1))
        
        
    def findMin(self,arr,idx):
        if len(arr) == idx: return sys.maxsize* 1
        return min(arr[idx],self.findMin(arr,idx+1))      
        

    def getMinMax(self, arr):
        # code here
        ans = [0]*2
        ans[0] = self.findMin(arr,0)
        ans[1] = self.findMax(arr,0) 
        return ans