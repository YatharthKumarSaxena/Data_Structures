from typing import Optional
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        a = head
        b = head.next
        while b:
            while b and b.val == a.val:
                b = b.next
            a.next = b
            if b: 
                a = a.next
                b = a.next
        return head