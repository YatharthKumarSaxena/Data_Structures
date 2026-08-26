class Solution:
    def doRecursion(self, ans, helper, open, closed, n):
        if open > n:
            return

        if open + closed == 2 * n:
            ans.append(helper)
            return

        if open > closed:
            self.doRecursion(
                ans, helper + ')', open, closed + 1, n
            )

        self.doRecursion(
            ans, helper + '(', open + 1, closed, n
        )

    def generateParentheses(self, n):
        ans = []
        self.doRecursion(ans, "", 0, 0, n)
        return ans