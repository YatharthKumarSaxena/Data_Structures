class Solution:
    def checkPerfectSquare(self, num) -> bool:
        root = int(num**0.5)
        if root**2 == num:
            return True
        return False
    def judgeSquareSum(self, c: int) -> bool:
        a = 0
        b = c
        while a<=b:
            if self.checkPerfectSquare(a) and self.checkPerfectSquare(b): return True
            elif not self.checkPerfectSquare(b):
                root = int(b**0.5)
                b = root**2
                a = c-b
            else:
                root = int(a**0.5)+1
                a = root**2
                b = c-a
        return False

        