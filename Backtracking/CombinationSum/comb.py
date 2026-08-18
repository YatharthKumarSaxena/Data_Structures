from typing import List

class Solution:
    def doBacktrack(self, ans, arr, helper, target, idx):
        if target == 0:
            ans.append(helper.copy())
            return
        n = len(arr)
        for i in range(idx,n):
            if arr[i] > target:
                break
            helper.append(arr[i])
            self.doBacktrack(ans,arr,helper,target-arr[i],i)
            helper.pop()

    def combinationSum(self, arr: List[int], target: int) -> List[List[int]]:
        ans = []
        arr.sort()
        self.doBacktrack(ans,arr,[],target,0)
        return ans