class Solution:
    def activitySelection(self, start: list[int], finish: list[int]) -> int:
        #code here
        n = len(start)
        activities = sorted(zip(start, finish), key=lambda x: x[1])
        currEnd = activities[0][1]
        removals = 0
        for i in range(1,n):
            nextStart = activities[i][0]
            nextEnd = activities[i][1]
            if nextStart <= currEnd:
                removals += 1
                currEnd = min(currEnd,nextEnd)
            else:
                currEnd = nextEnd
        totalActivities = n-removals
        return totalActivities