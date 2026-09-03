class Solution:
    def firstStableIndex(self, nums, k):
        n = len(nums)

        prefMax = [0] * n
        suffMin = [0] * n

        prefMax[0] = nums[0]
        suffMin[n - 1] = nums[n - 1]

        # Prefix maximum
        for i in range(1, n):
            prefMax[i] = max(nums[i], prefMax[i - 1])

        # Suffix minimum
        for i in range(n - 2, -1, -1):
            suffMin[i] = min(nums[i], suffMin[i + 1])

        # Find first stable index
        for i in range(n):
            score = prefMax[i] - suffMin[i]

            if score <= k:
                return i

        return -1