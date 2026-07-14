class Solution:
    def isKSortedArray(self, arr, n, k): 
        #code here.
        n = len(arr)
        check = []
        for i in range(n):
            check.append((arr[i],i))
        check.sort()
        for i in range(n):
            if abs(check[i][1]-i)>k: return "No"
        return "Yes"