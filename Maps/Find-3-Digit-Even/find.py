from typing import List

class Solution:
    def findEvenNumbers(self, digits: List[int]) -> List[int]:
        mp = {}
        n = len(digits)
        for i in range(n):
            mp[digits[i]] = mp.get(digits[i],0)+1
        ans = []
        for i in range(100,1000,2):
            val = i
            x = i
            a = x%10
            x //= 10
            b = x%10
            x //= 10
            c = x%10
            x //= 10
            if mp.get(a,0) > 0 and mp.get(b,0) > 0 and mp.get(c,0) > 0:
                temp = mp.copy()
                if temp[a] > 0: temp[a] = temp.get(a,0)-1
                else: continue
                if temp[b] > 0: temp[b] = temp.get(b,0)-1
                else: continue
                if temp[c] > 0: temp[c] = temp.get(c,0)-1
                else: continue
                ans.append(val)
        return ans