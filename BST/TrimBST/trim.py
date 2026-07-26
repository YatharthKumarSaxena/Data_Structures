class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None

class Solution:
    def trimBST(self, root, lo, hi):
        if not root:
            return

        while root.left is not None:
            if root.left.data > hi:
                root.left = root.left.left
            elif root.left.data < lo:
                root.left = root.left.right
            else:
                break

        while root.right is not None:
            if root.right.data < lo:
                root.right = root.right.right
            elif root.right.data > hi:
                root.right = root.right.left
            else:
                break

        self.trimBST(root.left, lo, hi)
        self.trimBST(root.right, lo, hi)

    def removekeys(self, root, l, r):
        dummy = Node(float('inf'))
        dummy.left = root

        self.trimBST(dummy, l, r)

        return dummy.left