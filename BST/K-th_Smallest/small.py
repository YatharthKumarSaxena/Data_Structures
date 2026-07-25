
class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None


class Solution:
    
    def prepareVector(self, root, v):
        if root==None: return
        self.prepareVector(root.left,v)
        v.append(root.data)
        self.prepareVector(root.right,v)

    def kthSmallest(self, root, k): 
        # code here
        v = []
        self.prepareVector(root,v)
        n = len(v)
        if k>n: return -1
        return v[k-1]