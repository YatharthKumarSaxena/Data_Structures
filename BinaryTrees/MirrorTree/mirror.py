class Node:
    def _init_(self, val):
        self.data = val
        self.right = None
        self.left = None


class Solution:
    def mirror(self, root):
        # code here
        if not root: return None
        temp = root.right
        root.right = root.left
        root.left = temp
        self.mirror(root.left)
        self.mirror(root.right)
        return root