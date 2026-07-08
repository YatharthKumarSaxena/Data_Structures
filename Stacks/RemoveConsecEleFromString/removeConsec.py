class Solution:
    def removeDuplicates(self, s: str) -> str:
        n = len(s)
        if n==0: return ""
        st = []
        st.append(s[0])
        for i in range(1,n):
            if not len(st) or s[i]!=st[-1]:
                st.append(s[i])
            else:  
                st.pop()
        ans = ""
        for i in range(len(st)):
            ans += st[i]
        return ans