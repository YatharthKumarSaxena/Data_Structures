class Node:
    def __init__(self, val):
        self.data = val
        self.right = None
        self.left = None

class Solution:
    def checkIsSymmetric(self, r1, r2):
        # code here
        if not r1 and not r2: return True
        elif (not r1 and r2) or (r1 and not r2): return False
        elif r1.data != r2.data: return False
        return self.checkIsSymmetric(r1.left,r2.right) and self.checkIsSymmetric(r1.right,r2.left)
        
    def isSymmetric(self, root):
        # code here
        if not root: return True
        return self.checkIsSymmetric(root.left,root.right)