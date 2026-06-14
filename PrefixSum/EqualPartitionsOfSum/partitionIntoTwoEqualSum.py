class Solution:
    def canSplit(self, arr):
        #code here
        n = len(arr)
        for i in range(1,n):
            arr[i] += arr[i-1]
        for i in range(n):
            if(2*arr[i]==arr[n-1]): return True
        return False