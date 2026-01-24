from typing import List

class Solution:
    def doRecursion(self, ans, helper, opening, closed, limit):
        if closed == limit:
            ans.append(helper)
            return
        if opening < limit: self.doRecursion(ans, helper+'(',opening+1,closed,limit)
        if opening>closed: self.doRecursion(ans, helper+')',opening,closed+1,limit)

    def generateParenthesis(self, n: int) -> List[str]:
        ans = []
        self.doRecursion(ans, "",0,0,n)
        return ans