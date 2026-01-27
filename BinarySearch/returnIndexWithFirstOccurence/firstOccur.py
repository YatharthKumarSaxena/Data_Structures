class Solution:
    def binarysearch(self, arr, k):
        # Code Here
        lo = 0
        hi = len(arr)-1
        idx = -1
        while lo <= hi:
            mid = lo + (hi-lo)//2
            if arr[mid]==k:
                idx = mid
                hi = mid-1
            elif arr[mid]>k: hi = mid-1
            else: lo = mid+1
        return idx
        