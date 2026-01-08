import sys

class Solution:
    def findMax(self,arr,idx):
        if len(arr) == idx: return sys.maxsize* -1
        return max(arr[idx],self.findMax(arr,idx+1))
    def largest(self, arr):
        # code here
        return self.findMax(arr,0)
        
        
