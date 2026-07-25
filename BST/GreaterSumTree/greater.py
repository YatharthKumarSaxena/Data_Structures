class Node:
    def __init__(self, value):
        self.data = value
        self.left = None
        self.right = None

class Solution:
    def __init__(self):
        self.sum = 0

    def transformTree(self, root):
        if not root:
            return

        self.transformTree(root.right)

        prevValue = root.data
        root.data = self.sum
        self.sum += prevValue

        self.transformTree(root.left)