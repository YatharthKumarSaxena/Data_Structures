from typing import List
from math import sqrt

class Solution1:
    def distinctPrimeFactors(self, nums: List[int]) -> int:
        prod = 1
        n = len(nums)
        for i in range(n):
            prod *= nums[i]
        i = 2
        ans = 0
        while prod>1:
            isDivisible = False
            while prod%i==0:
                prod //= i
                isDivisible = True
            if isDivisible: ans += 1
            i += 1
        return ans


class Solution2:
    def fillSieve(self, sieve: List[int]):   
        n = len(sieve)
        for i in range(2,int(sqrt(n))+1):
            if sieve[i]:
                for j in range(i**2,n,i):
                    sieve[j] = False
        return

    
    def distinctPrimeFactors(self, nums: List[int]) -> int:
        n = len(nums)
        mx = -1
        for i in range(n):
            if nums[i]>mx: mx = nums[i]

        sieve = [True] * (mx+1)

        if mx+1>0: sieve[0] = False
        if mx+1>1: sieve[1] = False

        self.fillSieve(sieve)

        possiblePrimes = []

        for i in range(mx+1):
            if sieve[i]: possiblePrimes.append(i)

        totalPossiblePrimes = len(possiblePrimes)
        taken = [False] * totalPossiblePrimes

        for i in range(totalPossiblePrimes):
            for j in range(n):
                if nums[j]%possiblePrimes[i]==0:
                    taken[i] = True
                    break

        ans = 0

        for i in range(totalPossiblePrimes):
            if taken[i]: ans+=1

        return ans



        