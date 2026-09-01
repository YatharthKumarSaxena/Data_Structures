class Solution:
    def checkOperator(self, op):
        if op == "+" or op == "%" or op == "-" or op == "*" or op == "/" or op == "^":
            return True
        return False

    def solve(self, val1, op, val2):
        return val1 + val2 + op

    def preToPost(self, s):
        st = []

        for i in range(len(s) - 1, -1, -1):
            term = s[i]

            if not self.checkOperator(term):
                st.append(term)
            else:
                val1 = st.pop()
                val2 = st.pop()

                res = self.solve(val1, term, val2)
                st.append(res)

        return st[-1]