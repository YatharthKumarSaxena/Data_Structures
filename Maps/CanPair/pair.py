class Solution:
    def canPair(self, arr, k):
        #code here.
        n = len(arr)
        if n%2!=0: return False
        mp = {}
        for i in range(n):
            rem = arr[i]%k
            mp[rem] = mp.get(rem,0) + 1
        for ele in mp:
            target = k-ele
            if ele == target or ele == 0:
                if mp[ele]%2!=0:
                    return False
            else: 
                if mp.get(target,0): 
                    if mp[ele]!=mp[target]:
                        return False
                else: return False
        return True
            