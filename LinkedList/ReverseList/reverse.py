
class Node:
    def __init__(self, val):
        self.data = val
        self.next = None


class Solution:
    def reverseList(self, head):
        # Code here
        prev = None
        curr = head
        next = head
        while curr:
            next = curr.next
            curr.next = prev
            prev = curr
            curr = next
        return prev