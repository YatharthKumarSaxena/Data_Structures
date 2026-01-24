#User function Template for python3

class Solution:
    def doRecursion(self,ans,helper,s): 
        if len(s) == 0:
            if len(helper) != 0:
                ans.append(helper)
            return
        self.doRecursion(ans,helper+s[0],s[1:])
        self.doRecursion(ans,helper,s[1:])  
        
    def AllPossibleStrings(self, s):   
        ans = []
        self.doRecursion(ans,"",s)
        ans.sort()
        return ans