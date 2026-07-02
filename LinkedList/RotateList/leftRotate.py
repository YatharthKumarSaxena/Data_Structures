
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class Solution:
    def rotate(self, head, k):
        # code here
        if not head or not head.next:
            return head
        listSize = 0
        temp = head
        tail = None
        while temp:
            tail = temp
            temp = temp.next
            listSize += 1
        k = k%listSize
        if k==0: return head
        temp = head
        for i in range(k-1):
            temp = temp.next
        tail.next = head
        head = temp.next
        temp.next = None
        return head