# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def sumFun(self, root, lo, hi):
        if root is None:
            return 0

        leftSum = self.sumFun(root.left, lo, hi)

        currSum = 0
        if lo <= root.val <= hi:
            currSum = root.val

        rightSum = self.sumFun(root.right, lo, hi)

        return leftSum + currSum + rightSum

    def rangeSumBST(self, root, low, high):
        return self.sumFun(root, low, high)