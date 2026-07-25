from typing import List, Optional
from collections import deque

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root is None:
            return []

        q = deque([(root,0)])
        ans = []

        while q:
            nodeTuple = q.popleft()
            pushLevel = nodeTuple[1]
            node = nodeTuple[0]
            if pushLevel == len(ans): ans.append([])
            level = pushLevel+1

            if pushLevel % 2 == 0:
                ans[pushLevel].append(node.val)
            else:
                ans[pushLevel].insert(0, node.val)

            if node.left:
                q.append([node.left,level])

            if node.right:
                q.append([node.right,level])

        return ans
        