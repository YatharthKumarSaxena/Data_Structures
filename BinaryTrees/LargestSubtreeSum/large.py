class Solution:
    def __init__(self):
        self.ans = float('-inf')

    def findMaxNodeValue(self, node):
        if node is None:
            return 0

        lSum = self.findMaxNodeValue(node.left)
        rSum = self.findMaxNodeValue(node.right)

        total = lSum + rSum + node.data

        self.ans = max(self.ans, total)

        return total

    def maxSubtreeSum(self, root):
        self.findMaxNodeValue(root)
        return self.ans