class Solution:
    def minRemoval(self, intervals):
        # code here
        intervals.sort()
        currEnd = intervals[0][1]
        n = len(intervals)
        removals = 0
        for i in range(1,n):
            nextStart = intervals[i][0]
            nextEnd = intervals[i][1]
            if nextStart < currEnd:
                removals += 1
                currEnd = min(currEnd,nextEnd)
            else:
                currEnd = nextEnd
        return removals