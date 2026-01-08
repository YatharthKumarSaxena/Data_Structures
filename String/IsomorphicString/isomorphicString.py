class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        list1 = ['\0'] * 256
        list2 = ['\0'] * 256
        for i in range(len(s)):
            s1 = ord(s[i])
            t1 = ord(t[i])
            if list1[s1] == '\0' and list2[t1] == '\0':
                list1[s1] = t[i]
                list2[t1] = s[i]
            elif list1[s1] != t[i] or list2[t1] != s[i]:
                return False
        return True