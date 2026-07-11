
class Node:
    def __init__(self, x):
        self.data = x
        self.next = None
        self.random = None   

class Solution:
    def cloneLinkedList(self, head):
        # code here
        if not head: return None
        ans = Node(head.data)
        maker = ans
        temp = head.next
        while temp:
            newNode = Node(temp.data)
            maker.next = newNode
            maker = maker.next
            temp = temp.next
        mp = {}
        tempA = head
        tempB = ans
        while tempA:
            mp[tempA] = tempB
            tempA = tempA.next
            tempB = tempB.next
        tempA = head
        tempB = ans
        while tempA:
            if tempA.random: tempB.random = mp[tempA.random]
            tempA = tempA.next
            tempB = tempB.next
        return ans