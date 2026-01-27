class Solution:
    def missingNumber(self, arr):
        # code here
        lo = 0
        hi = len(arr)-1
        idx = -1
        while lo <= hi:
            mid = lo + (hi-lo)//2
            number = mid+1
            if arr[mid]!=number:
                idx = number
                hi = mid-1
            else: lo = mid+1
        if idx == -1: return len(arr)+1
        return idx
        
    
        