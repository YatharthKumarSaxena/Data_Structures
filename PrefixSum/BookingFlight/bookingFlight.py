from typing import List

class Solution:
    def corpFlightBookings(self, bookings: List[List[int]], n: int) -> List[int]:
        bookSize = len(bookings)
        ans = [0]*n
        for i in range(bookSize):
            startIdx = bookings[i][0]-1
            endIdx = bookings[i][1]-1
            for j in range(startIdx,endIdx+1):
                ans[j] += bookings[i][2]
        return ans

