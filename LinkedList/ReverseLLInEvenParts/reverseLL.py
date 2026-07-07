from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    def reverseList(self, head: Optional[ListNode]):
        if head==None or head.next==None: return head
        newHead = self.reverseList(head.next)
        head.next.next = head
        head.next = None
        return newHead

    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        if left == right: return head
        n = 1
        temp = head
        a = None
        b = None
        c = None
        d = None
        while temp and n < right+1:
            if n==left-1:
                a = temp
            elif n==left:
                b = temp
            elif n==right:
                c = temp
            n += 1
            temp = temp.next
        d = c.next
        c.next = None
        t = self.reverseList(b)
        if a: a.next = t
        else: head = t
        b.next = d
        return head

    def reverseEvenLengthGroups(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next: return head
        gap = 2
        temp = head
        while temp:
            t = temp.next
            remLen = 0
            while remLen < gap and t:
                t=t.next
                remLen+=1
            t = temp.next
            if remLen == 0: break
            if remLen%2 == 0: temp.next = self.reverseBetween(t,1,remLen)
            count = remLen
            while count:
                if temp: 
                    temp = temp.next
                    count -= 1
                else: break
            gap += 1
        return head
