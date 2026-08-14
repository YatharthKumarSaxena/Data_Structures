class Solution:
    def findMaxProduct(self, arr):
        MOD = 1000000007
    
        n = len(arr)
    
        if n == 1:
            return arr[0]
    
        cn = 0
        cz = 0
        cp = 0
    
        maxEle = float('-inf')
    
        for i in range(n):
            if arr[i] > 0:
                cp += 1
            elif arr[i] < 0:
                cn += 1
            else:
                cz += 1
    
            maxEle = max(maxEle, arr[i])
    
        if cp == 0 and cn == 0:
            return 0
    
        if cz > 0 and cn == 1 and cp == 0:
            return 0
    
        if cz == 0:
            if cn == 0:
                prod = 1
    
                for i in range(n):
                    prod = (prod * arr[i]) % MOD
    
                return prod
    
        if cn % 2 == 0:
            prod = 1
    
            for i in range(n):
                if arr[i] != 0:
                    prod = (prod * arr[i]) % MOD
    
            return prod
    
        if cn % 2 != 0:
            prod = 1
            maxEle = float('-inf')
    
            for i in range(n):
                if arr[i] != 0:
                    prod = (prod * arr[i]) % MOD
    
                if arr[i] < 0:
                    maxEle = max(arr[i], maxEle)
    
            return (prod * pow(maxEle, -1, MOD)) % MOD
    
        return 0