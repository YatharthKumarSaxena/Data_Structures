class Solution:
    def solve(self, val1, op, val2):
        return op + val1 + val2

    def checkOperand(self, term):
        if 'a' <= term <= 'z':
            return True
        elif 'A' <= term <= 'Z':
            return True
        elif '0' <= term <= '9':
            return True
        return False

    def prio(self, op):
        if op == '+' or op == '-':
            return 1
        elif op == '*' or op == '/':
            return 2
        return 3

    def infixToPrefix(self, s):
        operand = []
        operators = []

        for term in s:

            if self.checkOperand(term):
                operand.append(term)

            elif term == '(':
                operators.append(term)

            elif not operators:
                operators.append(term)

            elif term == ')':
                while operators and operators[-1] != '(':
                    val2 = operand.pop()
                    val1 = operand.pop()

                    op = operators.pop()

                    res = self.solve(val1, op, val2)
                    operand.append(res)

                operators.pop()       # remove '('

            elif operators[-1] == '(':
                operators.append(term)

            elif self.prio(operators[-1]) < self.prio(term):
                operators.append(term)

            else:
                while (operators and
                       operators[-1] != '(' and
                       (self.prio(term) < self.prio(operators[-1]) or
                        (self.prio(term) == self.prio(operators[-1]) and term != '^'))):

                    val2 = operand.pop()
                    val1 = operand.pop()

                    op = operators.pop()

                    res = self.solve(val1, op, val2)
                    operand.append(res)

                operators.append(term)

        # Remaining operators
        while operators:
            val2 = operand.pop()
            val1 = operand.pop()

            op = operators.pop()

            res = self.solve(val1, op, val2)
            operand.append(res)

        return operand[-1]