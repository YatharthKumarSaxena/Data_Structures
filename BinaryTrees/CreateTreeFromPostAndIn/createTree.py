# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def buildPostAndIn(self, postorder, postLo, postHi, inorder, inLo, inHi):
        if postLo > postHi:
            return None

        root = TreeNode(postorder[postHi])

        in_idx = inLo
        while inorder[in_idx] != postorder[postHi]:
            in_idx += 1

        leftDis = in_idx - inLo

        root.left = self.buildPostAndIn(
            postorder,
            postLo,
            postLo + leftDis - 1,
            inorder,
            inLo,
            in_idx - 1 + leftDis - 1
        )

        root.right = self.buildPostAndIn(
            postorder,
            postLo + leftDis,
            postHi - 1,
            inorder,
            in_idx + 1,
            inHi
        )

        return root

    def buildTree(self, inorder, postorder):
        if not postorder:
            return None

        return self.buildPostAndIn(
            postorder,
            0,
            len(postorder) - 1,
            inorder,
            0,
            len(inorder) - 1
        )