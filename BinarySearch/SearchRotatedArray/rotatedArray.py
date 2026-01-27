from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        # Find the Peak Index
        peakIdx = -1 
        lo = 0 
        hi = len(nums)-1 
        while lo<=hi:
            mid = lo+ hi-lo //2 
            if nums[mid]==target: return mid  # Luck Hits
            if mid and mid<hi and nums[mid-1]<nums[mid] and nums[mid]>nums[mid+1]:
                peakIdx = mid+1 
                break 
             
            if mid and mid<hi and nums[mid-1]>nums[mid] and nums[mid]<nums[mid+1]:
                peakIdx = mid 
                break 
             
            elif nums[mid]>nums[hi]: lo = mid+1 
            else: hi = mid-1 
         
        idx = -1 
        if peakIdx == -1: # Means Only Single Binary Search will do its work
            lo = 0 
            hi = len(nums)-1 
            while lo<=hi:
                mid = lo+ hi-lo //2 
                if nums[mid]==target:
                    idx = mid 
                    break 
                  
                elif nums[mid]<target: lo = mid+1 
                else: hi = mid-1 
        else: # 2 Binary Search will give answer
            lo = 0 
            hi = peakIdx-1 
            if target>=nums[lo] and target <= nums[hi]:
                while lo<=hi:
                    mid = lo+ hi-lo //2 
                    if nums[mid]==target:
                        idx = mid 
                        break 
                    elif nums[mid]<target: lo = mid+1 
                    else: hi = mid-1 
            else :
                lo = peakIdx 
                hi = nums.size  -1 
                while lo<=hi:
                    mid = lo+ hi-lo //2 
                    if nums[mid]==target:
                        idx = mid 
                        break 
                     
                    elif nums[mid]<target: lo = mid+1 
                    else: hi = mid-1 
        return idx 
     
  