from typing import Optional
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        if not l1: return l2
        if not l2: return l1
        carry = 0
        temp1 = l1
        temp2 = l2
        prev = None
        while temp1 or temp2:
            if temp1 and temp2:
                temp1.val += (temp2.val+carry)
                if temp1.val >= 10:
                    temp1.val = (temp1.val)%10
                    carry = 1
                else: carry = 0
                prev = temp1
                temp1 = temp1.next
                temp2 = temp2.next
            elif temp1 and not temp2:
                temp1.val += carry
                if temp1.val >= 10:
                    temp1.val = (temp1.val)%10
                    carry = 1
                else: carry = 0
                prev = temp1
                temp1 = temp1.next
            else:
                temp2.val += carry
                if temp2.val >= 10:
                    temp2.val = (temp2.val)%10
                    carry = 1
                else: carry = 0
                prev.next = temp2
                prev = temp2
                temp2 = temp2.next 
        if carry:
            prev.next = ListNode(1)
        return l1