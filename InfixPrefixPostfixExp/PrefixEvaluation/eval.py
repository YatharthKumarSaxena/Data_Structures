class Solution:
    def checkOperator(self, op):
        return op in ["+", "%", "-", "*", "/", "^"]

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

        return pow(val1, val2)

    def evaluatePrefix(self, arr):
        st = []

        # Prefix -> right to left
        for i in range(len(arr) - 1, -1, -1):
            term = arr[i]

            if not self.checkOperator(term):
                st.append(int(term))

            else:
                val1 = st.pop()
                val2 = st.pop()

                res = self.solve(val1, term, val2)
                st.append(res)

        return st[-1]