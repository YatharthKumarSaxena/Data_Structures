class Solution:
    def findUnique(self, arr):
        # code here 
        n = len(arr)
        for i in range(1,n):
            arr[0] ^= arr[i]
        return arr[0]