class Solution:
    def isBalanced(self, s):
        # code here
        n = len(s)
        if n%2!=0: return False
        st = []
        for i in range(n):
            if s[i]=='(' or s[i]=='{' or s[i]=='[':
                st.append(s[i])
            elif len(st) and ((st[-1]=='(' and s[i]==')') or 
                (st[-1]=='{' and s[i]=='}') or 
                (st[-1]=='[' and s[i]==']')):
                    
                st.pop()
            else: return False
        return len(st)==0
        