# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def buildPreAndPost(self, preorder, preLo, preHi, postorder, postLo, postHi):
        if preLo > preHi:
            return None

        root = TreeNode(preorder[preLo])

        if preLo == preHi:
            return root

        leftDis = 0
        post = 0

        while postorder[post] != preorder[preLo + 1]:
            post += 1

        leftDis = post - postLo + 1

        root.left = self.buildPreAndPost(
            preorder,
            preLo + 1,
            preLo + leftDis,
            postorder,
            postLo,
            postLo + leftDis
        )

        root.right = self.buildPreAndPost(
            preorder,
            preLo + leftDis + 1,
            preHi,
            postorder,
            post + 1,
            postHi
        )

        return root

    def constructFromPrePost(self, preorder, postorder):
        if not preorder:
            return None

        return self.buildPreAndPost(
            preorder,
            0,
            len(preorder) - 1,
            postorder,
            0,
            len(postorder) - 1
        )