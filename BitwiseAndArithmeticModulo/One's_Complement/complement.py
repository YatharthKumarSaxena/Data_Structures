class Solution:
    def findComplement(self, num: int) -> int:
        n = num
        temp = n
        while n:
            temp = n
            n &= (n-1)
        temp = temp*2-1
        return temp^num