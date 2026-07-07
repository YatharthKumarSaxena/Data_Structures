from typing import Optional
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
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
    def pairSum(self, head: Optional[ListNode]) -> int:
        slow = head
        fast = head
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
        revPart = self.reverseList(slow.next)
        slow.next = None
        temp = head
        maxSum = -float('inf')
        while temp:
            currSum = temp.val + revPart.val
            maxSum = max(maxSum,currSum)
            revPart = revPart.next
            temp = temp.next
        return maxSum

