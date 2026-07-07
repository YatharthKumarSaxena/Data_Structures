from typing import Optional
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
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
        tempOdd.next = None
        if tempEven: tempEven.next = None
        temp = evenHead
        a = temp
        b = oddHead
        prev = None
        while temp:
            a = a.next
            temp.next = b
            prev = temp
            temp = temp.next
            if b: b = b.next
            if temp:
                temp.next = a
                prev = temp
                temp = temp.next
        if b:
            prev.next = b
        return evenHead