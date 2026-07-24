class Solution:
    def cntSubarrays(self, arr, k):
        # code here
        n = len(arr)
        if n == 0: return 0
        for i in range(1,n):
            arr[i] += arr[i-1]
        count = 0
        mp = {}
        for i in range(n):
            ele = arr[i]
            if ele == k: count += 1
            searchEle = ele - k
            if searchEle in mp:
                count += mp[searchEle]
            mp[arr[i]] = mp.get(arr[i],0) + 1
        return count