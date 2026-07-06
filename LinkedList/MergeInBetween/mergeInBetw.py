# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def mergeInBetween(self, list1: ListNode, a: int, b: int, list2: ListNode) -> ListNode:
        n = 1
        temp1 = list1
        aNode = None
        cNode = None
        dNode = None
        a = a+1
        b = b+1
        while temp1 and n < b+1:
            if n==a-1:
                aNode = temp1
            elif n==b:
                cNode = temp1
            n += 1
            temp1 = temp1.next
        if cNode: 
            dNode = cNode.next
            cNode.next = None
        if aNode: 
            aNode.next = list2
        else: list1 = list2
        tail = None
        temp2 = list2
        while temp2:
            tail = temp2
            temp2 = temp2.next
        tail.next = dNode
        return list1