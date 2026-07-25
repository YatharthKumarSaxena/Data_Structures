from collections import deque

class Solution:
    def levelOrder(self, root):
        if root is None:
            return []

        q = deque([root])
        ans = []

        while q:
            node = q.popleft()
            ans.append(node.data)

            if node.left:
                q.append(node.left)

            if node.right:
                q.append(node.right)

        return ans