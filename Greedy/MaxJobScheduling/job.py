class Solution:
    def jobScheduling(self, startTime: list[int],
                      endTime: list[int],
                      profit: list[int]) -> int:

        n = len(startTime)

        jobs = []

        for i in range(n):
            jobs.append((endTime[i], startTime[i], profit[i]))

        # Sort by end time
        jobs.sort()

        ends = [0] * n
        dp = [0] * (n + 1)

        for i in range(n):
            ends[i] = jobs[i][0]

        for i in range(1, n + 1):
            end = jobs[i - 1][0]
            start = jobs[i - 1][1]
            currProfit = jobs[i - 1][2]

            # Binary search for previous job
            # whose end time <= current start time
            left = 0
            right = i - 1

            while left < right:
                mid = left + (right - left) // 2

                if ends[mid] <= start:
                    left = mid + 1
                else:
                    right = mid

            if ends[left] <= start:
                prev = left + 1
            else:
                prev = left

            take = currProfit + dp[prev]
            skip = dp[i - 1]

            dp[i] = max(take, skip)

        return dp[n]