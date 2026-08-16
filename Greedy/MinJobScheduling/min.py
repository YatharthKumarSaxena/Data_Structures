class Solution:
    def jobSequencing(self, deadline: list[int], profit: list[int]) -> list[int]:
        n = len(deadline)

        jobs = []

        for i in range(n):
            jobs.append((profit[i], deadline[i]))

        # Highest profit first
        jobs.sort(reverse=True)

        maxDeadline = max(deadline)

        slot = [-1] * (maxDeadline + 1)

        count = 0
        totalProfit = 0

        for p, d in jobs:
            # Find latest available slot
            for t in range(d, 0, -1):
                if slot[t] == -1:
                    slot[t] = 1
                    count += 1
                    totalProfit += p
                    break

        return [count, totalProfit]