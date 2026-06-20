from math import sqrt

class Solution:
    def isPrime(self, n):
        if n<=1: return False

        for i in range(2,int(sqrt(n)+1)):
            if n%i == 0: return False

        return True

    def smallestValue(self, n: int) -> int:
        if self.isPrime(n): return n
        sum = 0
        m = n
        for i in range(2,int(sqrt(n)+1)):
            if m%i == 0 and self.isPrime(i):
                while m%i == 0: 
                    sum += i
                    m //= i
        
        for i in range(int(sqrt(n)),0,-1):
            if m%(n//i) ==0 and self.isPrime(n//i):
                while m % (n//i) == 0: 
                    sum += (n//i)
                    m //= (n//i)

        if sum == n: return n
        
        return self.smallestValue(sum)
        