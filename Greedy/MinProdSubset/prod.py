class Solution:
    def minProd(self, arr):
        cn = 0
        cz = 0
        cp = 0
        n = len(arr)

        minEle = float('inf')

        for i in range(n):
            if arr[i] > 0:
                cp += 1
            elif arr[i] < 0:
                cn += 1
            else:
                cz += 1

            minEle = min(minEle, arr[i])

        if cz > 0 and cn == 0:
            return 0

        elif cz == 0 and cp > 0 and cn == 0:
            return minEle

        prod = 1
        maxEle = float('-inf')

        for i in range(n):
            if arr[i] != 0:
                prod *= arr[i]

            if arr[i] < 0:
                maxEle = max(maxEle, arr[i])

        if cn > 0 and cn % 2 == 0:
            return prod // maxEle

        return prod