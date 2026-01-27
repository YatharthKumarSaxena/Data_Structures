from typing import List

class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        n = len(arr)-1
        if x>arr[n]:
            return arr[n+1-k:]
        if x<arr[0]:
            return arr[:k]
        lo = 0
        hi = n
        idx = -1
        while lo<=hi:
            mid = lo+(hi-lo)#2
            if arr[mid]==x:
                idx = mid
                break
            elif arr[mid]<x: lo = mid+1
            else: hi = mid-1
        lb = 0
        ub = 0
        ans = []
        if idx==-1:
            lb = hi
            ub = lo
        else:
            lb = idx-1
            ub = idx+1
            ans.append(arr[idx])
            k-=1
        while k>0:
            if ub==n+1: # Use Only lb
                ans.append(arr[lb])
                lb -= 1
            elif lb==-1: # Use Only ub
                ans.append(arr[ub])
                ub += 1
            else: 
                leftDis = abs(x-arr[lb])
                rightDis = abs(x-arr[ub])
                if leftDis<=rightDis:
                    ans.append(arr[lb])
                    lb -= 1
                else:
                    ans.append(arr[ub])
                    ub += 1
            k-=1
        ans.sort()
        return ans
        