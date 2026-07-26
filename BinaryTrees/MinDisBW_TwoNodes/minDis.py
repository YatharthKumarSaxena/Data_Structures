# A binary tree node
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
        if not root:
            return None
    
        if root.data == n1 or root.data == n2:
            return root
    
        left1 = self.checkRootExists(root.left, n1)
        left2 = self.checkRootExists(root.left, n2)
    
        if left1 and left2:
            return self.lca(root.left, n1, n2)
    
        if (not left1) and (not left2):
            return self.lca(root.right, n1, n2)
    
        return root
        
    def findHeight(self,root,val):
        if not root: return float('inf')
        elif root.data == val: return 0
        else: return 1+min(self.findHeight(root.left,val),self.findHeight(root.right,val))
        
    def findDist(self, root, a, b):
        # code here
        if a==b: return 0
        checkRoot = self.lca(root,a,b)
        minDis = -1
        return self.findHeight(checkRoot,a) + self.findHeight(checkRoot,b)

            
        