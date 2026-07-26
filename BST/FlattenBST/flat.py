class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None

class Solution:
    def makePreOrder(self, root, ans):
        if not root:
            return

        self.makePreOrder(root.left, ans)
        ans.append(root)
        self.makePreOrder(root.right, ans)

    def flattenBST(self, root):
        if not root:
            return None

        nodes = []
        self.makePreOrder(root, nodes)

        n = len(nodes)

        for i in range(n - 1):
            nodes[i].right = nodes[i + 1]
            nodes[i].left = None

        nodes[n - 1].right = None
        nodes[n - 1].left = None

        return nodes[0]