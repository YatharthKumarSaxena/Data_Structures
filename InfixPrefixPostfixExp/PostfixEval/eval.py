class Solution:
    def checkOperator(self, op):
        if op == "+" or op == "-" or op == "*" or op == "/" or op == "^":
            return True
        return False

    def solve(self, val1, op, val2):
        if op == "+":
            return val1 + val2

        elif op == "-":
            return val1 - val2

        elif op == "*":
            return val1 * val2

        elif op == "/":
            res = int(val1 / val2)

            if val1 * val2 < 0 and val1 % val2 != 0:
                return res - 1

            return res

        return int(pow(val1, val2))

    def evaluatePostfix(self, arr):
        st = []

        for term in arr:

            if not self.checkOperator(term):
                st.append(int(term))

            else:
                val2 = st.pop()
                val1 = st.pop()

                res = self.solve(val1, term, val2)
                st.append(res)

        return st[-1]