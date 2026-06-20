from math import sqrt

class Solution:
    def isPrime(self, n):
        if n<=1: return False

        for i in range(2,int(sqrt(n)+1)):
            if n%i == 0: return False

        return True
