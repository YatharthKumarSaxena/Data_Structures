from typing import Optional,List
import heapq

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        n = len(lists)
        if n==0: return None
        if n==1: return lists[0]
        pq = []
        for i in range(n):
            temp = lists[i]
            while temp:
                heapq.heappush(pq,(temp.val,id(temp),temp))
                temp = temp.next
        if len(pq)==0: return None
        head = pq[0][2]
        heapq.heappop(pq)
        temp = head
        while len(pq):
            temp.next = heapq.heappop(pq)[2]
            temp = temp.next
        temp.next = None
        return head