from typing import List

class Solution:
    def check(self,trip,time,tripTime):
        totalTrip = 0
        for i in range(len(time)):
            totalTrip += tripTime//time[i]
        return trip <= totalTrip

    def minimumTime(self, time: List[int], totalTrips: int) -> int:
        lo = 1
        hi = min(time) * totalTrips
        ans = -1
        while lo<=hi:
            mid = lo+(hi-lo)//2
            if self.check(totalTrips,time,mid):
                ans = mid
                hi = mid-1
            else: lo = mid+1
        return ans