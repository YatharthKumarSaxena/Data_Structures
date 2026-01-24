class Solution:
    def calcFact(self,n : int) -> int:
        ans = 1
        for i in range(2,n+1):
            ans *= i
        return ans

    def findPermutation(self,ans: str,n : int,k :int,remString : str) -> str:
        if n==1:
            ans += remString
            return ans
        fact = self.calcFact(n-1)
        idx = k//fact
        if k%fact==0:
            idx-=1
            k=fact
        else: k = k%fact
        ans += remString[idx]
        remString = remString[:idx] + remString[idx+1:]
        return self.findPermutation(ans,n-1,k,remString)

    def getPermutation(self, n: int, k: int) -> str:
        remString = ""
        for i in range(1,n+1):
            remString += str(i)
        return self.findPermutation("",n,k,remString)
        
        