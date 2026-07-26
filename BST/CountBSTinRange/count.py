class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None

class Solution:
    def prepareInVector(self, root, ans):
        if not root: return
        self.prepareInVector(root.left, ans)
        ans.append(root.data)
        self.prepareInVector(root.right, ans)
        
    def getCount(self, root, l, h):
        # Your code here
        count = 0
        nodes = []
        self.prepareInVector(root,nodes)
        n = len(nodes)
        for i in range(n):
            if l<=nodes[i] and nodes[i]<=h: count += 1
        return count