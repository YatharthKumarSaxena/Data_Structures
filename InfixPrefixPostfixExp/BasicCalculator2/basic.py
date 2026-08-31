class Solution:
    def prio(self, op):
        if op == '/' or op == '*':
            return 2
        return 1

    def solve(self, val1, op, val2):
        if op == '+':
            return val1 + val2
        elif op == '-':
            return val1 - val2
        elif op == '*':
            return val1 * val2
        return int(val1 / val2)

    def calculate(self, s):
        n = len(s)

        st = []
        op = []

        i = 0

        while i < n:

            if s[i] == ' ':
                i += 1
                continue

            elif '0' <= s[i] <= '9':
                num = 0

                while i < n and '0' <= s[i] <= '9':
                    num = num * 10 + (ord(s[i]) - ord('0'))
                    i += 1

                st.append(num)
                i -= 1

            elif not op or self.prio(s[i]) > self.prio(op[-1]):
                op.append(s[i])

            else:
                while op and self.prio(s[i]) <= self.prio(op[-1]):
                    val2 = st.pop()
                    val1 = st.pop()

                    operation = op.pop()

                    result = self.solve(val1, operation, val2)
                    st.append(result)

                op.append(s[i])

            i += 1

        # Remaining operators
        while op:
            val2 = st.pop()
            val1 = st.pop()

            operation = op.pop()

            st.append(self.solve(val1, operation, val2))

        return st[-1]