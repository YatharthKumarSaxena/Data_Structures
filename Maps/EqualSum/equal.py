class Solution:
    def findPairs(self, arr): 
        #code here.  
        mp = {}
        n = len(arr)
        for i in range(n):
            for j in range(i+1,n):
                sum = arr[i] + arr[j]
                if sum in mp: return True
                else:
                    mp[sum] = mp.get(sum,0)
        return False