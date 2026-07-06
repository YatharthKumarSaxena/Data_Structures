from typing import Optional
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        if not head: return None
        ans = None
        temp = None
        iterator = head
        while iterator:
            if iterator.val != val:
                if not ans:
                    if not temp:
                        temp = iterator
                    ans = temp
                else:
                    temp.next = iterator
                    temp = temp.next
            iterator = iterator.next
        if temp:
            temp.next = None
        return ans