class Solution:

    def getTargetLevel(self, node, target, level):
        if not node:
            return -1

        if node.data == target:
            return level

        left = self.getTargetLevel(node.left, target, level + 1)
        if left != -1:
            return left

        return self.getTargetLevel(node.right, target, level + 1)

    def getLevel(self, node, target):
        level = self.getTargetLevel(node, target, 1)
        return level