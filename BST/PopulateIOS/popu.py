class Solution:
    def prepareInVector(self, root, ans):
        if not root:
            return

        self.prepareInVector(root.left, ans)
        ans.append(root)
        self.prepareInVector(root.right, ans)

    def populateNext(self, root):
        check = []
        self.prepareInVector(root, check)

        n = len(check)

        for i in range(n - 1):
            check[i].next = check[i + 1]

        if n > 0:
            check[n - 1].next = None