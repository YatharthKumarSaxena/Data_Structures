class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        st = []
        ans = []

        for ch in s:
            if ch == '(':
                st.append(len(ans))
                ans.append(ch)

            elif ch == ')':
                if st:
                    st.pop()
                    ans.append(ch)

            else:
                ans.append(ch)

        # Remove unmatched '(' from right to left
        while st:
            index = st.pop()
            ans.pop(index)

        return ''.join(ans)