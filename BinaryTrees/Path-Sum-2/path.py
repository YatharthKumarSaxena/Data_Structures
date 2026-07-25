from typing import Optional,List
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def findPaths(self, root, helper, ans, target):
        if not root: return
        helper.append(root.val)
        if root.left == None and root.right == None:
            if root.val == target:
                ans.append(helper.copy())
            helper.pop()
            return
        self.findPaths(root.left,helper,ans,target-root.val)
        self.findPaths(root.right,helper,ans,target-root.val)
        helper.pop()
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        ans = []
        self.findPaths(root,[],ans,targetSum)
        return ans