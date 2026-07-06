from typing import Optional
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def swapNodes(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        first = None
        second = head
        fast = head

        count = 1

        while fast:
            if count == k:
                first = fast

            if count > k:
                second = second.next

            fast = fast.next
            count += 1

        first.val, second.val = second.val, first.val

        return head