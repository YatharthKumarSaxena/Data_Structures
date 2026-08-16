class Solution:
    def startStation(self, gas: list[int], cost: list[int]) -> int:
        total = 0
        tank = 0
        start = 0
        n = len(gas)

        for i in range(n):
            total += gas[i] - cost[i]
            tank += gas[i] - cost[i]

            if tank < 0:
                tank = 0
                start = i + 1

        if total < 0:
            return -1

        return start