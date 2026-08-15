import heapq

class Solution:
    def fractionalKnapsack(self, val, wt, capacity):
        pq = []

        n = len(val)

        for i in range(n):
            qty = val[i] / wt[i]
            heapq.heappush(pq, (-qty, i))

        maxQty = 0.0

        while pq and capacity > 0:
            qty, idx = heapq.heappop(pq)
            qty = -qty

            weight = wt[idx]
            value = val[idx]

            if capacity >= weight:
                capacity -= weight
                maxQty += value
            else:
                maxQty += (capacity / weight) * value
                capacity = 0

        return maxQty