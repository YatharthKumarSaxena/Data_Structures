class Solution:
    def getMinSteps(self, n):
        # code here
        ans = [0] * (n+1)
        for i in range(2,n+1):
            divideBy2 = ans[i//2] if i%2 == 0 else float('inf')
            divideBy3 = ans[i//3] if i%3 == 0 else float('inf')
            ans[i] = 1+min(divideBy2,divideBy3,ans[i-1])
        return ans[n]
        