from typing import List

class Solution:
    def doRecursion(self, ans, helper,arr,index):
        ans.append(helper.copy())
        for i in range(index,len(arr)):
            if i>index and arr[i]==arr[i-1]:
                continue
            helper.append(arr[i])
            self.doRecursion(ans,helper,arr,i+1)
            helper.pop()

    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        ans = []
        nums.sort()
        self.doRecursion(ans,[],nums,0)
        return ans
        