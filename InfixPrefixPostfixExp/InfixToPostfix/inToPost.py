class Solution:
    def solve(self, val1, op, val2):
        return val1 + val2 + op

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

    def infixToPostfix(self, s):
        operand = []
        operators = []

        for term in s:

            # Operand
            if self.checkOperand(term):
                operand.append(term)

            # Opening bracket
            elif term == '(':
                operators.append(term)

            # No operator present
            elif not operators:
                operators.append(term)

            # Closing bracket
            elif term == ')':
                while operators and operators[-1] != '(':
                    val2 = operand.pop()
                    val1 = operand.pop()

                    op = operators.pop()

                    res = self.solve(val1, op, val2)
                    operand.append(res)

                # Remove '('
                operators.pop()

            # '(' is on top
            elif operators[-1] == '(':
                operators.append(term)

            # Current operator has higher priority
            elif self.prio(operators[-1]) < self.prio(term):
                operators.append(term)

            # Equal/lower priority
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