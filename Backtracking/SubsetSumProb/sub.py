class Solution:

    def doBacktrack(self, arr, sample, target, idx, ans):
        n = len(arr)

        if idx == n:
            if target == 0:
                ans.append(sample.copy())
            return

        if arr[idx] <= target:
            sample.append(arr[idx])

            self.doBacktrack(
                arr,
                sample,
                target - arr[idx],
                idx + 1,
                ans
            )

            sample.pop()

        self.doBacktrack(
            arr,
            sample,
            target,
            idx + 1,
            ans
        )

    def isSubsetSum(self, arr, sum):
        sample = []
        ans = []

        self.doBacktrack(
            arr,
            sample,
            sum,
            0,
            ans
        )

        if len(ans):
            return True

        return False

