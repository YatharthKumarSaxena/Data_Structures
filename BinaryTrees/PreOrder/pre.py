'''
# Node Class:
class Node:
    def __init__(self,val):
        self.data = val
        self.left = None
        self.right = None
'''

class Solution1:
    def doPreOrder(self,root,ans):
        if not root: return
        ans.append(root.data)
        self.doPreOrder(root.left,ans)
        self.doPreOrder(root.right,ans)
    def preOrder(self, root):
        ans = []
        self.doPreOrder(root,ans)
        return ans


class Solution2:
    def preOrder(self, root):
        ans = []
        st = [root]
        while len(st):
            node = st[-1]
            ans.append(node.data)
            st.pop()
            if node.right: st.append(node.right)
            if node.left: st.append(node.left)
        return ans
