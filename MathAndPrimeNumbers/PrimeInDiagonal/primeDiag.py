from math import sqrt
from typing import List

class Solution:

    def isPrime(self,n):
        if n<=1: return False
        for i in range(2,int(sqrt(n)+1)):
            if n%i == 0: return False
        return True

    def diagonalPrime(self, nums: List[List[int]]) -> int:
        maxPrime = 0
        n = len(nums)
        for i in range(n):
            if self.isPrime(nums[i][i]):
                maxPrime = max(maxPrime,nums[i][i])
            
            if self.isPrime(nums[i][n-i-1]):
                maxPrime = max(maxPrime,nums[i][n-i-1])
            
        return maxPrime
