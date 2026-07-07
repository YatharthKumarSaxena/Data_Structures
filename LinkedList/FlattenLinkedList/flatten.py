from typing import Optional
# # Definition for a Node.
class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child


class Solution:
    def flatten(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if not head: return head
        temp = head
        while temp:
            while temp and not temp.child:
                temp = temp.next
            if not temp:
                break
            a = temp.next
            c = temp
            temp.next = temp.child
            temp = temp.next
            temp.prev = c
            c.child = None
            c.next = self.flatten(temp)
            while temp.next:
                temp = temp.next
            if a: a.prev = temp
            temp.next = a
            temp = temp.next
        return head
            
        