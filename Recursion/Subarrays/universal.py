#User function Template for python3
class Solution:
    def generateSubArray(self,start,end,arr,ans):
        if end == len(arr):
            return
        l = []
        for i in range(start,end+1):
            l.append(arr[i])
        ans.append(l)
        self.generateSubArray(start,end+1,arr,ans)
    def getSubArrays(self, arr):
        #code here
        ans = []
        for i in range(len(arr)):
            self.generateSubArray(i,i,arr,ans)
        return ans
        