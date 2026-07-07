from typing import Optional,List

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def splitListToParts(self, head: Optional[ListNode], k: int) -> List[Optional[ListNode]]:
        if k==1: return [head]
        n = 0
        temp = head
        while temp:
            n += 1
            temp =temp.next
        totalSize = n//k
        extraSize = n%k
        ans = [None]*k
        temp = head
        listNum = 0
        while temp:
            sizeOfLL = totalSize
            if extraSize:
                sizeOfLL += 1
                extraSize -= 1
            count = 1
            newHead = temp
            while count < sizeOfLL:
                temp = temp.next
                count += 1
            t = temp
            temp = temp.next
            t.next = None
            ans[listNum] = newHead
            listNum += 1
        return ans