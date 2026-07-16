class Solution:
    def reorganizeString(self, s: str) -> str:
        mp = {}
        n = len(s)
        if n<=1: return s
        for i in range(n):
            mp[s[i]] = mp.get(s[i],0) + 1
        maxFreq = mp[s[0]]
        for key,freq in mp.items():
            if freq > (n+1)/2: return ""
            if maxFreq < freq:
                maxFreq = freq
        ans = ['0']*n
        idx = 0
        for ele,freq in mp.items():
            if maxFreq == freq:
                while mp[ele]:
                    ans[idx] = ele
                    mp[ele] -= 1
                    idx += 2
                break
        if idx < n:
            for ele,freq in mp.items():
                while mp[ele]:
                    if idx >= n:break
                    ans[idx] = ele
                    mp[ele] -= 1
                    idx += 2
        idx = 1
        for ele,freq in mp.items():
            while mp[ele]>0 and idx<n:
                ans[idx] = ele
                mp[ele] -= 1
                idx += 2
        return "".join(ans)