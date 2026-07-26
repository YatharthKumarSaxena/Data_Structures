# =========================
# Solution 1 : O(n²)
# =========================

class Solution:
    def isMaxTree(self, root, value):
        if not root:
            return True

        if root.data >= value:
            return False

        return (self.isMaxTree(root.left, value) and
                self.isMaxTree(root.right, value))

    def isMinTree(self, root, value):
        if not root:
            return True

        if root.data <= value:
            return False

        return (self.isMinTree(root.left, value) and
                self.isMinTree(root.right, value))

    def isBST(self, root):
        if not root:
            return True

        if (not self.isMaxTree(root.left, root.data) or
            not self.isMinTree(root.right, root.data)):
            return False

        return self.isBST(root.left) and self.isBST(root.right)


# =========================
# Solution 2 : O(n)
# =========================

class Solution:
    def helper(self, root, low, high):
        if not root:
            return True

        if root.data <= low or root.data >= high:
            return False

        return (self.helper(root.left, low, root.data) and
                self.helper(root.right, root.data, high))

    def isBST(self, root):
        return self.helper(root, float('-inf'), float('inf'))