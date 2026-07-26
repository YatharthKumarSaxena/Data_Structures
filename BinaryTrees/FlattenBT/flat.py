from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        if not root: return
        l = root.left
        r = root.right
        root.left = None
        root.right = None
        self.flatten(l)
        self.flatten(r)
        if l:
            root.right = l
            temp = l
            while temp.right: temp = temp.right
            temp.right = r
        else:
            root.right = r
        