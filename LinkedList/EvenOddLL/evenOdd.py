from typing import Optional
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next: return head
        oddHead = head
        evenHead = head.next
        tempOdd = oddHead
        tempEven = evenHead
        while tempOdd.next and tempOdd.next.next:
            tempOdd.next = tempOdd.next.next
            tempEven.next = tempEven.next.next
            tempOdd = tempOdd.next
            tempEven = tempEven.next
        tempOdd.next = evenHead
        return oddHead
