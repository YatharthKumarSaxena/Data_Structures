from typing import Optional
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def reverseList(self, head):
        prev = None
        curr = head
        Next = head
        while curr:
            Next = curr.next
            curr.next = prev
            prev = curr
            curr = Next
        return prev
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if not head or not head.next: return head
        slow = head
        fast = head
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
        secondList = slow.next
        slow.next = None
        secondList = self.reverseList(secondList)
        tempB = secondList
        temp = head
        tempA = head
        while tempA and tempB:
            tempA = tempA.next
            temp.next = tempB
            temp = temp.next
            tempB = tempB.next
            temp.next = tempA
            temp = temp.next
        return head

        