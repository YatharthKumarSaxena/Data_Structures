class NumArray:

    def __init__(self, nums):
        self.n = len(nums)
        self.sumTree = [0] * (4 * self.n)

        self.buildSumTree(
            self.sumTree, nums, 0, 0, self.n - 1
        )

    def buildSumTree(self, sumTree, nums, i, lo, hi):
        if lo == hi:
            sumTree[i] = nums[lo]
            return

        mid = lo + (hi - lo) // 2

        self.buildSumTree(
            sumTree, nums, 2*i + 1, lo, mid
        )

        self.buildSumTree(
            sumTree, nums, 2*i + 2, mid + 1, hi
        )

        sumTree[i] = sumTree[2*i + 1] + sumTree[2*i + 2]

    def updateSumTree(self, sumTree, i, idx, val, lo, hi):
        if lo == hi:
            sumTree[i] = val
            return

        mid = lo + (hi - lo) // 2

        if idx <= mid:
            self.updateSumTree(
                sumTree, 2*i + 1, idx, val, lo, mid
            )
        else:
            self.updateSumTree(
                sumTree, 2*i + 2, idx, val, mid + 1, hi
            )

        sumTree[i] = sumTree[2*i + 1] + sumTree[2*i + 2]

    def update(self, index, val):
        self.updateSumTree(
            self.sumTree, 0, index, val, 0, self.n - 1
        )

    def getSumEle(self, sumTree, i, l, r, lo, hi):
        if l > hi or r < lo:
            return 0

        if l <= lo and hi <= r:
            return sumTree[i]

        mid = lo + (hi - lo) // 2

        left = self.getSumEle(
            sumTree, 2*i + 1, l, r, lo, mid
        )

        right = self.getSumEle(
            sumTree, 2*i + 2, l, r, mid + 1, hi
        )

        return left + right

    def sumRange(self, left, right):
        return self.getSumEle(
            self.sumTree, 0, left, right, 0, self.n - 1
        )