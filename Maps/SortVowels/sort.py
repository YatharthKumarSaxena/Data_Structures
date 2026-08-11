class Solution:
    def sortVowels(self, s: str) -> str:
        mp1 = {}   # vowel -> frequency
        mp2 = {}   # vowel -> first occurrence

        n = len(s)
        ans = ['#'] * n

        # Frequency + first occurrence
        for i in range(n):
            if s[i] in "aeiou":
                mp1[s[i]] = mp1.get(s[i], 0) + 1

                if s[i] not in mp2:
                    mp2[s[i]] = i

        # frequency -> list of vowels
        mp3 = {}

        for ele, count in mp1.items():
            if count not in mp3:
                mp3[count] = []

            mp3[count].append(ele)

        # Frequency descending
        # Same frequency -> first occurrence ascending
        for count in mp3:
            mp3[count].sort(key=lambda x: mp2[x])

        idx = 0

        # Keep consonants at their original positions
        for i in range(n):
            if s[i] not in "aeiou":
                ans[i] = s[i]

        # Fill vowels
        for count in sorted(mp3, reverse=True):
            for ele in mp3[count]:
                for _ in range(count):
                    while ans[idx] != '#':
                        idx += 1

                    ans[idx] = ele
                    idx += 1

        return ''.join(ans)