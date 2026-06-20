from math import sqrt

class Solution1:
    def checkPerfectNumber(self, num: int) -> bool:
        factorSum = 1
        for i in range(2,int(sqrt(num))+1):
            if num%i == 0 and i!=(num//i):
                factorSum += (i + num//i)
        if int(sqrt(num))*int(sqrt(num)) == num:
            factorSum += int(sqrt(num))
        if factorSum == num: return True
        return False
    

class Solution2:
    def checkPerfectNumber(self, num: int) -> bool:
        if num==1: return False
        factorSum = 0
        for i in range(1,int(sqrt(num)+1)):
            if num % i == 0: factorSum += i
        for i in range(int(sqrt(num)),1,-1):
            if num % (num//i) == 0: factorSum += (num//i)
        if factorSum == num: return True
        return False