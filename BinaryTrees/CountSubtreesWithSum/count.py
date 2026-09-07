class Solution:
    def __init__(self):
        self.ans = 0

    def giveSumNodeValue(self, node, target):
        if node is None:
            return 0

        lSum = self.giveSumNodeValue(node.left, target)
        rSum = self.giveSumNodeValue(node.right, target)

        total = lSum + rSum + node.data

        if total == target:
            self.ans += 1

        return total

    def countSubtrees(self, root, x):
        self.giveSumNodeValue(root, x)
        return self.ans