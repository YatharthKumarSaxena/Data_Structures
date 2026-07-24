class Solution:
    def maxLen(self, arr):
        # code here
        n = len(arr)
        if n==0: return 0
        maxLen = 0
        pre0 = [0]*n
        pre1 = [0]*n
        if arr[0]:
            pre1[0] = 1
        else:
            pre0[0] = 1
            
        for i in range(1,n):
            pre0[i] += pre0[i-1]
            pre1[i] += pre1[i-1]
            if arr[i]:
                pre1[i] += 1
            else:
                pre0[i] += 1
        mp = {}
        for i in range(n):
            diff = pre0[i]-pre1[i]
            if diff == 0: maxLen = max(maxLen,i+1)
            else:
                if diff not in mp:
                    mp[diff] = i
                if diff in mp:
                    maxLen = max(maxLen,i-mp[diff])
        return maxLen