class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None

class Solution:
    def findHeight(self, root, level):
        if root is None:
            return 0

        return 1 + max(self.findHeight(root.left, level + 1),
                       self.findHeight(root.right, level + 1))

    def isBalanced(self, root):
        if root is None:
            return True

        leftHeight = self.findHeight(root.left, 0)
        rightHeight = self.findHeight(root.right, 0)

        diffHeight = abs(leftHeight - rightHeight)

        if diffHeight > 1:
            return False

        return (self.isBalanced(root.left) and
                self.isBalanced(root.right))