class Solution:
    def countDistinct(self, arr, k):
        # code here
        n = len(arr)
        ans = [0] * (n-k+1)
        i = 0
        j = k
        mp = {}
        for t in range(k):
            mp[arr[t]] = mp.get(arr[t],0) + 1

        ans[0] = len(mp)
        
        for t in range(1,n-k+1):
            mp[arr[i]] = mp.get(arr[i],0) - 1
            if mp[arr[i]]==0: del mp[arr[i]]
            mp[arr[j]] = mp.get(arr[j],0) + 1
            ans[t]=len(mp)
            i += 1
            j += 1

        return ans