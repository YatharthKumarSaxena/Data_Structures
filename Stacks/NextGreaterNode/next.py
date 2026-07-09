from typing import List,Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    def nextLargerNodes(self, head: Optional[ListNode]) -> List[int]:
        arr = []
        temp = head
        while temp:
            arr.append(temp.val)
            temp = temp.next
        n = len(arr)
        st = [arr[n-1]]
        ans = [0]*n
        for i in range(n-2,-1,-1):
            while len(st) and st[-1]<=arr[i]: st.pop()
            if len(st): ans[i] = st[-1]
            st.append(arr[i])
        return ans