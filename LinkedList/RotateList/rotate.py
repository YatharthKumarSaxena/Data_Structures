from typing import Optional

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        listSize = 0
        temp = head
        tail = None
        while temp:
            tail = temp
            temp = temp.next
            listSize += 1
        k = k%listSize
        temp = head
        for i in range(listSize-k-1):
            temp = temp.next
        tail.next = head
        head = temp.next
        temp.next = None
        return head

        