from collections import deque

class Solution:
    def buildTree(self, nodeList):
        n = len(nodeList)

        if n == 0:
            return None

        qu = deque()

        root = nodeList[0]
        qu.append(root)

        i = 1
        j = 2

        while qu and i < n:
            node = qu.popleft()

            leftNode = None
            rightNode = None

            if nodeList[i]:
                leftNode = nodeList[i]

            if j < n and nodeList[j]:
                rightNode = nodeList[j]

            if leftNode:
                qu.append(leftNode)

            if rightNode:
                qu.append(rightNode)

            node.left = leftNode
            node.right = rightNode

            i += 2
            j += 2

        return root