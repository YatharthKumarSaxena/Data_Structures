class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None


class Solution:
    
    def findMax(self, root):
        if not root:
            return float('-inf')
        
        return max(
            root.data,
            self.findMax(root.left),
            self.findMax(root.right)
        )
    
    def findMin(self, root):
        if not root:
            return float('inf')
        
        return min(
            root.data,
            self.findMin(root.left),
            self.findMin(root.right)
        )