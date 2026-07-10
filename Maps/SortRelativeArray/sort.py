class Solution:
    def relativeSort(self, arr1, arr2):
        mp = {}
        n2 = len(arr2)
        for i in range(n2):
            mp[arr2[i]] = mp.get(arr2[i],0)
        n1 = len(arr1)
        for i in range(n1):
            mp[arr1[i]] = mp.get(arr1[i],0) +1
        ans = []
        remEle = []
        
        for i in range(n2):
            if arr2[i] in mp:
                ans.extend([arr2[i]]*mp[arr2[i]])
                del mp[arr2[i]]
            
        for key in sorted(mp):
            remEle.extend([key] * mp[key])

        ans.extend(remEle)
        arr1[:] = ans 
        
        return arr1

