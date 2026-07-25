class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None

class Solution:
    def transformIntoBST(self, lo, hi, arr):
        if lo > hi:
            return None

        mid = lo + (hi - lo) // 2

        root = Node(arr[mid])

        root.left = self.transformIntoBST(lo, mid - 1, arr)
        root.right = self.transformIntoBST(mid + 1, hi, arr)

        return root

    def sortedArrayToBST(self, arr):
        n = len(arr)
        return self.transformIntoBST(0, n - 1, arr)