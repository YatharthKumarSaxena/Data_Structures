class Node:

    def __init__(self, val):
        self.data = val
        self.right = None
        self.left = None 


class Solution:
    def levelOrderTraversal(self,root,level,ans):
        if not root: return
        if level == len(ans): ans.append(root.data)
        else: ans[level] = root.data
        self.levelOrderTraversal(root.right,level+1,ans)
        self.levelOrderTraversal(root.left,level+1,ans)

    def leftView(self, root):
        # code here
        # code here
        ans = []
        self.levelOrderTraversal(root,0,ans)
        return ans