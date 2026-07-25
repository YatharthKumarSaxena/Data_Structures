'''
Definition for Node
class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None
'''

class Solution:
    def LCA(self, root, n1, n2):
        if root is None:
            return None

        elif root.data == n1.data or root.data == n2.data:
            return root

        elif root.data < n1.data and root.data < n2.data:
            return self.LCA(root.right, n1, n2)

        elif root.data > n1.data and root.data > n2.data:
            return self.LCA(root.left, n1, n2)

        else:
            return root