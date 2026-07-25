from typing import Optional
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def checkPath(self, root, target):
        if not root: return False
        if root.left == None and root.right == None:
            if root.val == target: return True
            return False
        return self.checkPath(root.left,target-root.val) or self.checkPath(root.right,target-root.val)
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        return self.checkPath(root,targetSum)