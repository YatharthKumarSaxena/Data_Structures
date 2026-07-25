# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def buildPreAndIn(self, preorder, preLo, preHi, inorder, inLo, inHi):
        if preLo > preHi:
            return None

        root = TreeNode(preorder[preLo])

        in_idx = inLo
        while inorder[in_idx] != preorder[preLo]:
            in_idx += 1

        leftDis = in_idx - inLo

        root.left = self.buildPreAndIn(
            preorder,
            preLo + 1,
            preLo + leftDis,
            inorder,
            inLo,
            in_idx - 1 + leftDis - 1
        )

        root.right = self.buildPreAndIn(
            preorder,
            preLo + leftDis + 1,
            preHi,
            inorder,
            in_idx + 1,
            inHi
        )

        return root

    def buildTree(self, preorder, inorder):
        if not preorder:
            return None

        return self.buildPreAndIn(
            preorder,
            0,
            len(preorder) - 1,
            inorder,
            0,
            len(inorder) - 1
        )