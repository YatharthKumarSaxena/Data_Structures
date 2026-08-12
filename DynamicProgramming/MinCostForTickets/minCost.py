class Solution:
    def doDP(self, day, days, costs, dp):
        n = len(days)

        if day > days[n - 1]:
            return 0

        if dp[day] != -1:
            return dp[day]

        checkDayExist = False

        for i in range(n):
            if days[i] == day:
                checkDayExist = True
                break

        if not checkDayExist:
            dp[day] = self.doDP(day + 1, days, costs, dp)
            return dp[day]

        dp[day] = min(
            costs[0] + self.doDP(day + 1, days, costs, dp),
            costs[1] + self.doDP(day + 7, days, costs, dp),
            costs[2] + self.doDP(day + 30, days, costs, dp)
        )

        return dp[day]

    def mincostTickets(self, days, costs):
        n = len(days)

        dp = [-1] * (days[n - 1] + 1)

        return self.doDP(days[0], days, costs, dp)