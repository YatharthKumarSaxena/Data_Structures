class Solution:
    def checkOperator(self, op):
        return op in ['+', '%', '-', '*', '/', '^']

    def solve(self, val1, op, val2):
        return op + val1 + val2

    def postToPre(self, s):
        st = []

        for term in s:
            if not self.checkOperator(term):
                st.append(term)
            else:
                val2 = st.pop()
                val1 = st.pop()

                res = self.solve(val1, term, val2)
                st.append(res)

        return st[-1]