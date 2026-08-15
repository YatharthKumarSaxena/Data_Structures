class Solution:
    def findMinArrowShots(self, intervals):
        intervals.sort(key=lambda x: x[1])

        currEnd = intervals[0][1]
        n = len(intervals)
        arrows = 1

        for i in range(1, n):
            nextStart = intervals[i][0]

            if nextStart > currEnd:
                arrows += 1
                currEnd = intervals[i][1]

        return arrows