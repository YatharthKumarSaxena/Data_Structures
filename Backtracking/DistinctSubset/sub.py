class Solution:
    def doRecursion(self, ans, arr, helper, index):
        n = len(arr)
        ans.append(helper.copy())
        for i in range(index,n):
            if i>index and arr[i-1]==arr[i]:
                continue
            helper.append(arr[i])
            self.doRecursion(ans,arr,helper,i+1)
            helper.pop()
    def findSubsets(self, arr):
        # code here
        ans = []
        arr.sort()
        self.doRecursion(ans,arr,[],0)
        return ans