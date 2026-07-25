# BST Node
class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None


class Solution:
    def search(self, root, key):
        while root:
            if root.data == key:
                return True
            elif root.data > key:
                root = root.left
            else:
                root = root.right

        return False