class Solution:
    def findMin(self, n: int) -> int:
        ops = 0

        while n:
            if n - 10 >= 0:
                n -= 10
            elif n - 5 >= 0:
                n -= 5
            elif n - 2 >= 0:
                n -= 2
            else:
                n -= 1

            ops += 1

        return ops