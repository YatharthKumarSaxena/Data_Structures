class Solution:
    def maxSubarraySum(self, arr, k):
        # code here 
        n = len(arr)
        maxSum = 0
        for j in range(k):
            maxSum += arr[j]
        j = k
        prevSum = maxSum
        while j<n:
            currSum = (prevSum - arr[j-k] + arr[j])
            if currSum > maxSum:
                maxSum = currSum
            prevSum = currSum
            j += 1
        return maxSum
            