class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None


class Solution:
    def checkRootExists(self,root,value):
        if not root: return False
        if root.data == value: return True
        return self.checkRootExists(root.left,value) or self.checkRootExists(root.right,value)
    def lca(self, root, n1, n2):
        # code here
        if not root: return None
        elif root.data == n1 or root.data == n2: return root
        elif ((self.checkRootExists(root.left,n1) and self.checkRootExists(root.right,n2)) or 
        (self.checkRootExists(root.left,n2) and self.checkRootExists(root.right,n1))): return root
        elif (self.checkRootExists(root.left,n1) and not self.checkRootExists(root.right,n2)): return self.lca(root.left,n1,n2)
        else: return self.lca(root.right,n1,n2)
