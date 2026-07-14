class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        n1 = len(word1)
        n2 = len(word2)
        if n1 != n2: return False
        mp1,mp2 = {},{}
        for i in range(n1):
            mp1[word1[i]] = mp1.get(word1[i],0) + 1
            mp2[word2[i]] = mp2.get(word2[i],0) + 1

        if len(mp1) != len(mp2):
            return False

        for key,value in mp1.items():
            if key not in mp2:
                return False
        
        f1,f2 = [],[]

        for key,value in mp1.items():
            f1.append(value)

        for key,value in mp2.items():
            f2.append(value)

        f1.sort()
        f2.sort()

        return f1 == f2