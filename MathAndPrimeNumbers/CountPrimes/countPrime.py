from typing import List
from math import sqrt

class Solution:
    def fillSieve(self, sieve: List):
        n = len(sieve)
        for i in range(2,int(sqrt(n)+1)):
            if sieve[i]:
                for j in range(i*i,n,i):
                    sieve[j] = False

    def countPrimes(self, n: int) -> int:
        if n<=2: return 0
        n = n-1
        sieve = [True] * (n+1)
        sieve[0] = False
        sieve[1] = False
        self.fillSieve(sieve)
        totalPrimes = 0
        for i in range(n+1):
            if sieve[i]: totalPrimes += 1
        return totalPrimes