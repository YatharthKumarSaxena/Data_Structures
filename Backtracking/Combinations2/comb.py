class Solution:
    
    def doRecursion(self, ans, helper, n, k):
        if len(helper) == k:
            check = 0
            for i in range(k):
                check += helper[i]
            if check == n:
                ans.append(helper.copy())
            return
    
        size = len(helper)
    
        for i in range(1, 10):
            if size > 0 and helper[size - 1] < i:
                helper.append(i)
                self.doRecursion(ans, helper, n, k)
                helper.pop()
    
            if size == 0:
                helper.append(i)
                self.doRecursion(ans, helper, n, k)
                helper.pop()

    def combinationSum(self, n, k):
        # code here
        ans = []
        self.doRecursion(ans, [], n, k)
        return ans