class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None


class Solution:
    def findPath(self, root, helper, ans):
        if root is None:
            return

        if root.left is None and root.right is None:
            helper.append(root.data)
            ans.append(helper)
            return

        helper.append(root.data)

        self.findPath(root.left, helper.copy(), ans)
        self.findPath(root.right, helper.copy(), ans)

    def paths(self, root):
        ans = []
        self.findPath(root, [], ans)
        return ans


# Example
if __name__ == "__main__":
    # Tree:
    #       1
    #      / \
    #     2   3
    #    / \
    #   4   5

    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)

    obj = Solution()
    print(obj.paths(root))