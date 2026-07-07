from typing import Optional
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None or head.next == None: return head
        sortMaker = None
        temp = head
        while temp and temp.next:
            if temp.val == temp.next.val:
                value = temp.val
                while temp and temp.val == value:
                    temp = temp.next
            else:
                if not sortMaker:
                    sortMaker = temp
                    head = sortMaker
                else:
                    sortMaker.next = temp
                    sortMaker = sortMaker.next
                if temp: temp = temp.next
        if temp and sortMaker and sortMaker.val != temp.val: sortMaker.next = temp
        else:
            if not sortMaker and temp: return temp
            elif sortMaker: sortMaker.next = None
            else: return  None
        return head