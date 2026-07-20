'''
class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None
'''

class Solution1:
    def postOrder(self, root):
        # code here
        ans = []
        st1 = [root]
        st2 = []
        while len(st1):
            node = st1[-1]
            st2.append(node)
            st1.pop()
            if node.left:
                st1.append(node.left)
            if node.right:
                st1.append(node.right)
        while len(st2):
            node = st2[-1]
            ans.append(node.data)
            st2.pop()
        return ans

class Solution2:
    def doPostOrder(self,root,ans):
        if not root: return
        self.doPostOrder(root.left,ans)
        self.doPostOrder(root.right,ans)
        ans.append(root.data)
    def postOrder(self, root):
        # code here
        ans = []
        self.doPostOrder(root,ans)
        return ans
        