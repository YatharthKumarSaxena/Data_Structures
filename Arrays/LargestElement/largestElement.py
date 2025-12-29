class Solution:
    def largest(self, arr):
        # code here
        length = len(arr)
        if length == 1: return arr[0]
        max = arr[0]
        for i in range(1,length):
            if max<arr[i]: max = arr[i]
        return max
        
