import heapq

'''Structure of a Binary Tree Node
class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None
'''

class Solution:
    def prepareVector(self, root, v):
        if root==None: return
        self.prepareVector(root.left,v)
        v.append(root.data)
        self.prepareVector(root.right,v)
    def kthLargest(self, root, k):
        # code here
        v = []
        self.prepareVector(root,v)
        n = len(v)
        if k>n: return -1
        pq = []
        for i in range(n):
            heapq.heappush(pq,v[i])
            if len(pq)>k: heapq.heappop(pq)
        return pq[0]