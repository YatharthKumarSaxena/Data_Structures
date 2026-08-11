class Solution:
    def frequencySort(self, s: str) -> str:
        mp1 = {}
        n = len(s)

        for i in range(n):
            mp1[s[i]] = mp1.get(s[i], 0) + 1

        mp2 = {}

        ans = ""

        for ele,count in mp1.items():
            if count not in mp2:
                mp2[count] = []

            mp2[count].append(ele)

        for count in sorted(mp2, reverse=True):
            for ch in mp2[count]:
                ans += ch * count

        return ans
