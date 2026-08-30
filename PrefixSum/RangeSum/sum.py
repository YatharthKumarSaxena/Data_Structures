class Solution:
    def querySum(self, arr, queries):
        n = len(arr)

        for i in range(1, n):
            arr[i] += arr[i - 1]

        ans = []

        for i in range(len(queries)):
            left = queries[i][0] - 1
            right = queries[i][1] - 1

            if left == 0:
                ans.append(arr[right])
            else:
                ans.append(arr[right] - arr[left - 1])

        return ans