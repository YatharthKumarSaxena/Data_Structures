from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def findLength(self, head: ListNode) -> int:
        temp = head
        ans = 0
        while temp:
            ans += 1
            temp = temp.next
        return ans
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        lenA = self.findLength(headA)
        lenB = self.findLength(headB)
        totalMove = abs(lenA-lenB)
        if lenA > lenB:
            for i in range(totalMove):
                headA = headA.next
        else:
            for i in range(totalMove):
                headB = headB.next
        while headA:
            if headA == headB:
                return headA
            headA = headA.next
            headB = headB.next
        return None

        