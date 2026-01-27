from typing import List

class Solution:
    def checkCapacityFitWithinHours(self, hours, capacity, piles):
        n = len(piles)
        sumOfPiles = 0
        speed = 0
        for i in range(n):
            if piles[i]<capacity: speed+=1
            elif piles[i]%capacity==0: speed += piles[i]//capacity
            else: speed += piles[i]//capacity + 1
        
        return speed <= hours

    def minEatingSpeed(self, piles: List[int], hours: int) -> int:
        n = len(piles)
        # Decide hi
        hi = -1
        for i in range(n):
            hi = max(hi,piles[i])
        
        # Decide lo
        lo = 0
        for i in range(n): lo += piles[i]
        lo = lo//hours
        if lo==0: lo = 1
        ans = 0
        while lo<=hi:
            capacity = lo+(hi-lo)//2
            if self.checkCapacityFitWithinHours(hours,capacity,piles):
                ans = capacity
                hi = capacity-1
            else: lo = capacity+1
        
        return ans
        