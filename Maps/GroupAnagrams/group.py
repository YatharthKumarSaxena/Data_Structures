class Solution:
    def anagrams(self, arr):
        # code here
        ans = []
        mp = {}
        n = len(arr)
        for i in range(n):
            value = arr[i]
            key = ''.join(sorted(arr[i]))
            if key in mp:
                mp[key].append(value)
            else:
                mp[key] = [value]
        
        for key,value in mp.items():
            ans.append(value)
        return ans