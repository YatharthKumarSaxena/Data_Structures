class Solution:   
    def peakElement(self, arr):
        # Code here
        lo = 0
        hi = len(arr)-1
        if hi == 0: return 0
        if arr[0]>arr[1]: return 0
        if arr[hi-1]<arr[hi]: return hi
        ans = -1
        while lo<=hi:
            mid = lo+(hi-lo)//2
            if mid > 0 and mid<len(arr)-1 and arr[mid-1]<arr[mid] and arr[mid]>arr[mid+1]:
                return mid
            elif mid<len(arr)-1 and arr[mid]<arr[mid+1]: lo = mid+1
            else: hi = mid-1
        return ans 
        