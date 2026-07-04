from typing import Optional
#  Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        lo = ListNode(2000)
        hi = ListNode(3000)
        tempLo = lo
        tempHi = hi
        temp = head
        while temp:
            if temp.val < x:
                tempLo.next = temp
                tempLo = tempLo.next
            else:
                tempHi.next = temp
                tempHi = tempHi.next
            temp = temp.next
        tempHi.next = None
        tempLo.next = hi.next
        return lo.next

        