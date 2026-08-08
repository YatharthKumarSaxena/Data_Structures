class Solution:
    def diffArray(self, arr, opr):
        n = len(arr)

        diff = [0] * (n + 1)

        for L, R, V in opr:
            diff[L] += V
            diff[R + 1] -= V

        # Prefix sum
        for i in range(1, n):
            diff[i] += diff[i - 1]

        # Add original array
        for i in range(n):
            diff[i] += arr[i]

        diff.pop()

        return diff