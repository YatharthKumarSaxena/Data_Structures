class Solution:
    def findLongestChain(self, pairs: list[list[int]]) -> int:
        pairs.sort()

        ans = 0
        n = len(pairs)

        currEnd = pairs[0][1]
        removals = 0

        for i in range(1, n):
            nextStart = pairs[i][0]
            nextEnd = pairs[i][1]

            if nextStart <= currEnd:
                removals += 1
                currEnd = min(currEnd, nextEnd)
            else:
                currEnd = nextEnd

        return n - removals