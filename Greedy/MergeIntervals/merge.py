from typing import List

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()
        currStart = intervals[0][0]
        currEnd = intervals[0][1]
        n = len(intervals)
        ans = []
        for i in range(1,n):
            nextStart = intervals[i][0]
            nextEnd = intervals[i][1]
            if nextStart <= currEnd:
                currEnd = max(currEnd,nextEnd)
            else:
                ans.append([currStart,currEnd])
                currEnd = nextEnd
                currStart = nextStart
        ans.append([currStart,currEnd])
        return ans