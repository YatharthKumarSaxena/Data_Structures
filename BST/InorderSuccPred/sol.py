class Solution:
    def prepareInVector(self, root, ans):
        if not root:
            return

        self.prepareInVector(root.left, ans)
        ans.append(root)
        self.prepareInVector(root.right, ans)

    def findPreSuc(self, root, key):
        check = []
        self.prepareInVector(root, check)

        pred = None
        succ = None

        for node in check:
            val = node.data

            if key > val:
                pred = node
            elif key < val:
                succ = node
                break

        return [pred, succ]