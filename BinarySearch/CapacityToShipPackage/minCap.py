from typing import List

class Solution:
    def checkCapacityFitWithinDays(self,days, capacity, weights):
        n = len(weights)
        sumOfWeights = 0
        for i in range(n):sumOfWeights += weights[i]
        idx = 0
        while days and sumOfWeights:
            shipWeight = 0
            while idx<n and shipWeight<capacity:
                if shipWeight+weights[idx]>capacity: break
                shipWeight += weights[idx]
                sumOfWeights -= weights[idx]
                idx += 1
            
            days -= 1
        
        if sumOfWeights!=0: return False
        return True
    
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        n = len(weights)
        # Decide lo
        lo = -1
        for i in range(n):
            lo = max(lo,weights[i])
        
        # Decide hi
        hi = 0
        for i in range(n):hi += weights[i]
        ans = 0
        while lo<=hi:
            capacity = lo+(hi-lo)//2
            if self.checkCapacityFitWithinDays(days,capacity,weights):
                ans = capacity
                hi = capacity-1
            else: lo = capacity+1
        
        return ans
    
