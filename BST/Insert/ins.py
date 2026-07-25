class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class Solution:
    def insert(self, root, key):
        # code here 
        newNode = Node(key)
        if not root: return newNode
        temp = root
        while temp:
            if temp.left == None and temp.data > key:
                temp.left = newNode
                break
            elif temp.right == None and temp.data < key:
                temp.right = newNode
                break
            elif temp.data < key:
                temp = temp.right
            else:
                temp = temp.left
        return root