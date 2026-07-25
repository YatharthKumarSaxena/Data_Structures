class Node:
    def __init__(self, val):
        self.data = val
        self.right = None
        self.left = None

class Solution:
    def leftBoundary(self, root):
        if not root:
            return []

        if root.left is None:
            return [root.data]

        leftB = []
        temp = root

        while temp.left is not None or temp.right is not None:
            leftB.append(temp.data)

            if temp.left:
                temp = temp.left
            else:
                temp = temp.right

        return leftB

    def rightBoundary(self, root):
        if not root:
            return []

        rightB = []
        temp = root

        while temp.left is not None or temp.right is not None:
            rightB.append(temp.data)

            if temp.right:
                temp = temp.right
            else:
                temp = temp.left

        return rightB

    def leafNodes(self, root, leaves):
        if not root:
            return

        if root.left is None and root.right is None:
            leaves.append(root.data)
            return

        self.leafNodes(root.left, leaves)
        self.leafNodes(root.right, leaves)

    def boundaryTraversal(self, root):
        if not root:
            return []

        if root.left is None and root.right is None:
            return [root.data]

        leftB = self.leftBoundary(root)
        rightB = self.rightBoundary(root.right)

        leaves = []
        self.leafNodes(root, leaves)

        boundary = []

        for x in leftB:
            boundary.append(x)

        for x in leaves:
            boundary.append(x)

        for i in range(len(rightB) - 1, -1, -1):
            boundary.append(rightB[i])

        return boundary
        