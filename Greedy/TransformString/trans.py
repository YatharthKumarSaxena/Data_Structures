class Solution:
    def transform(self, s1: str, s2: str) -> int:
        n1 = len(s1)
        n2 = len(s2)

        if n1 != n2:
            return -1

        mp1 = {}
        mp2 = {}

        for i in range(n1):
            mp1[s1[i]] = mp1.get(s1[i], 0) + 1
            mp2[s2[i]] = mp2.get(s2[i], 0) + 1

        for ele in mp1:
            if ele not in mp2:
                return -1

            if mp1[ele] != mp2[ele]:
                return -1

        i = n1 - 1
        j = n2 - 1
        ans = 0

        while i >= 0 and j >= 0:
            if s1[i] == s2[j]:
                i -= 1
                j -= 1
            else:
                i -= 1
                ans += 1

        return ans