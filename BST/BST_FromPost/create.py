# Definition for Node
class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None


class Solution:
    def buildPostAndIn(self, postorder, postLo, postHi, inorder, inLo, inHi):
        if postLo > postHi:
            return None

        root = Node(postorder[postHi])

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

    def constructTree(self, post):
        if not post:
            return None

        inorder = post.copy()
        inorder.sort()

        return self.buildPostAndIn(
            post,
            0,
            len(post) - 1,
            inorder,
            0,
            len(inorder) - 1
        )