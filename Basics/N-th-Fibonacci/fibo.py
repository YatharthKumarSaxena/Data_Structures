class Solution:

    def nthFibonacci(self, n):
        if n <= 1:
            return n

        a = 0
        b = 1

        for i in range(n - 1):
            temp = a
            a = b
            b = temp + b

        return b