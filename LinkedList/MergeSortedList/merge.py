from typing import Optional

# Definition for singly-linked list.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        ans = None
        a = list1
        b = list2

        if a==None: return b
        if b==None: return a

        if a.val < b.val:
            ans = a
            a = a.next

        else:
            ans = b
            b = b.next
        
        temp = ans
        while a and b:
            if a.val < b.val:
                temp.next = a
                a = a.next
            else:
                temp.next = b
                b = b.next        
            temp = temp.next

        if b: temp.next = b
        if a: temp.next = a
        return ans