from typing import List

class Solution:
    def doBacktrack(self, ans, arr, helper, target, idx):

        if target == 0:
            ans.append(helper.copy())
            return

        n = len(arr)

        for i in range(idx, n):

            # Same level par duplicate skip
            if i > idx and arr[i] == arr[i - 1]:
                continue

            if arr[i] > target:
                break

            helper.append(arr[i])

            # i + 1 -> current element dobara use nahi hoga
            self.doBacktrack(
                ans, arr, helper, target - arr[i], i + 1
            )

            helper.pop()

    def combinationSum2(self, arr: List[int], target: int) -> List[List[int]]:
        ans = []
        helper = []

        arr.sort()

        self.doBacktrack(ans, arr, helper, target, 0)

        return ans