class Solution: 
    def selectionSort(self, arr):
        #code here
        n = len(arr)
        for i in range(n-1):
            idx = i
            for j in range(i+1,n) :
                if arr[idx] > arr[j]: 
                    idx = j
            arr[idx],arr[i] = arr[i],arr[idx]