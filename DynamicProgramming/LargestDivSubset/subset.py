class Solution:
    def largestSubset(self, arr):
        arr.sort()

        n = len(arr)

        # dp[i] = largest valid subset starting from i
        dp = [1] * n

        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n):
                if arr[j] % arr[i] == 0:
                    dp[i] = max(dp[i], dp[j] + 1)

        # Lexicographically greatest starting element
        start = 0
        maxLen = 0

        for i in range(n - 1, -1, -1):
            if dp[i] > maxLen:
                maxLen = dp[i]
                start = i

        ans = []
        current = start

        ans.append(arr[current])

        while dp[current] > 1:

            # Find largest possible next element
            for j in range(n - 1, current, -1):
                if (arr[j] % arr[current] == 0 and
                    dp[j] == dp[current] - 1):

                    current = j
                    ans.append(arr[current])
                    break

        return ans