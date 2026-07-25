# Definition for Node
class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None


class Solution:
    def buildPreAndIn(self, preorder, preLo, preHi, inorder, inLo, inHi):
        if preLo > preHi:
            return None

        root = Node(preorder[preLo])

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

    def preToBST(self, pre):
        if not pre:
            return None

        inorder = pre.copy()
        inorder.sort()

        return self.buildPreAndIn(
            pre,
            0,
            len(pre) - 1,
            inorder,
            0,
            len(inorder) - 1
        )