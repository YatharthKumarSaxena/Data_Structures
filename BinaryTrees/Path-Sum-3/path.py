from typing import Optional

# Definition for a binary tree node.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def findPaths(self, root, target):
        if not root: return 0
        count = 1 if target == root.val else 0
        return self.findPaths(root.left,target-root.val) + self.findPaths(root.right,target-root.val) + count
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        if not root: return 0
        return ( self.findPaths(root, targetSum) + self.pathSum(root.left, targetSum) + self.pathSum(root.right, targetSum) )
        