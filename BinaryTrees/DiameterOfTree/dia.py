class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None


class Solution:
    def findMaxDia(self, root):
        if root is None:
            return 0

        return 1 + max(self.findMaxDia(root.left),
                       self.findMaxDia(root.right))

    def diameter(self, root):
        if root is None:
            return 0

        dia = self.findMaxDia(root.left) + self.findMaxDia(root.right)

        return max(dia,
                   max(self.diameter(root.left),
                       self.diameter(root.right)))


if __name__ == "__main__":
    # Create tree:
    #      1
    #     / \
    #    2   3

    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)

    obj = Solution()
    print("Diameter (in edges):", obj.diameter(root))