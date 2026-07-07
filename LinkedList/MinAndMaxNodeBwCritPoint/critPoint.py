from typing import Optional,List
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        if not head or not head.next or not head.next.next:
            return [-1,-1]
        firstMaxIdx = -1
        secondMaxIdx = -1
        firstMinIdx = -1
        secondMinIdx = -1
        a = head
        b = head.next
        c = head.next.next
        ptr = 2
        minDis = float('inf')
        maxDis = -1
        while c:
            if (a.val < b.val and b.val > c.val) or (a.val > b.val and b.val < c.val):
                if firstMinIdx == -1:
                    firstMinIdx = ptr
                    firstMaxIdx = ptr
                else:
                    if secondMinIdx != -1: 
                        firstMinIdx = secondMinIdx
                    secondMinIdx = ptr
                    secondMaxIdx = ptr
                    dis = secondMinIdx - firstMinIdx
                    minDis = min(minDis,dis)
            ptr += 1
            a = a.next
            b = b.next
            c = c.next
        if minDis == float('inf'):
            return [-1,-1]
        maxDis = secondMaxIdx - firstMaxIdx
        return [minDis,maxDis]
        
                