class Solution:
    def pushZerosToEnd(self, arr):
        # code here
        n = len(arr)
        helper = [0] * n
        idx = 0

        for i in range(n):
            if arr[i] != 0:
                helper[idx] = arr[i]
                idx += 1

        for i in range(n):
            arr[i] = helper[i]
