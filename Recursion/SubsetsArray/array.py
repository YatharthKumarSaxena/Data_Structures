class Solution:
    def doRecursion(self, ans, helper, arr):
        if len(arr) == 0:
            ans.append(helper.copy())
            return
        val = arr[0]
        self.doRecursion(ans,helper,arr[1:])
        helper.append(val)
        self.doRecursion(ans,helper,arr[1:])
        helper.pop()  
        
    def subsets(self, arr):
        # code here
        ans = []
        self.doRecursion(ans,[],arr)
        return ans
        