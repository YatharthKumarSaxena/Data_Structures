class Solution:
    def doRecursion(self, n, helper, ans):
        if len(helper) == n :
            ans.append(helper)
            return
        self.doRecursion(n,helper+'0',ans)
        self.doRecursion(n,helper+'1',ans)
        
    def binstr(self, n):
        # code here
        ans = []
        self.doRecursion(n,"",ans)
        return ans