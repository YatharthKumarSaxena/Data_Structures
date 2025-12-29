class Solution:
    def getSecondLargest(self, arr):
        # Code Here
        length = len(arr)
        if length == 1: return -1
        smax = -1
        max = arr[0]
        for i in range(1,length):
            if max < arr[i] :
                smax = max
                max = arr[i]
            elif smax < arr[i] and max != arr[i]:
                smax = arr[i]
        return smax