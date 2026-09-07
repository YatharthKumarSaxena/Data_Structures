class Solution:
    def __init__(self):
        self.ans = 0

    def dfs(self, root):
        if root is None:
            return (0, 0)

        leftSum, leftCount = self.dfs(root.left)
        rightSum, rightCount = self.dfs(root.right)

        totalSum = root.val + leftSum + rightSum
        totalCount = 1 + leftCount + rightCount

        if root.val == totalSum // totalCount:
            self.ans += 1

        return (totalSum, totalCount)

    def averageOfSubtree(self, root):
        self.dfs(root)
        return self.ans