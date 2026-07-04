
class Node:
    def __init__(self, data):
        self.data = data
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
    def isPalindrome(self, head):
        # code here
        slow = head
        fast = head
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
        temp1 = head
        temp2 = self.reverseList(slow.next)
        while temp2:
            if temp1.data != temp2.data: return False
            temp1 = temp1.next
            temp2 = temp2.next
        return True
        