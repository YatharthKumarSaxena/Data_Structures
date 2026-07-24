from typing import Optional
from collections import deque

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    first = None
    def makeParentPair(self,parent,root):
        if not root: return
        if root.left: parent[root.left] = root
        if root.right: parent[root.right] = root
        self.makeParentPair(parent,root.left)
        self.makeParentPair(parent,root.right)

    def findStartNode(self, root, start):
        if not root: return
        if root.val == start:
            self.first = root
            return
        self.findStartNode(root.left,start)
        self.findStartNode(root.right,start)
    def amountOfTime(self, root: Optional[TreeNode], start: int) -> int:
        self.findStartNode(root,start)
        isInfected = set()
        parent = {}
        self.makeParentPair(parent,root)
        qu = deque()
        qu.append((self.first,0))
        totalTime = 0
        while len(qu):
            levelNode = qu.popleft()
            node = levelNode[0]
            totalTime = levelNode[1]
            if node not in isInfected:
                nextLevel = totalTime+1
                isInfected.add(node)
                if node in parent:
                    if parent[node] not in isInfected:
                        qu.append((parent[node],nextLevel))
                if node.left:
                    if node.left not in isInfected:
                        qu.append((node.left,nextLevel))
                if node.right:
                    if node.right not in isInfected:
                        qu.append((node.right,nextLevel))
        return totalTime
