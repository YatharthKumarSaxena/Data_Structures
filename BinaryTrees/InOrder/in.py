'''
class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None
'''

class Solution:
    def inOrder(self, root):
        # code here
        st = []
        ans = []
        curr = root
        while curr or len(st): 
            while curr:
                st.append(curr)
                curr = curr.left
            else:
                node = st[-1]
                st.pop()
                ans.append(node.data)
                curr = node.right
        return ans


class Solution:
    def doInOrder(self,root,ans):
        if not root: return
        self.doInOrder(root.left,ans)
        ans.append(root.data)
        self.doInOrder(root.right,ans)
    def inOrder(self, root):
        # code here
        ans = []
        self.doInOrder(root,ans)
        return ans
        