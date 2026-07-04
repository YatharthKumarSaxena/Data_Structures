# Structure of linked list Node
class Node:
  def __init__(self, x):
      self.data = x
      self.next = None

class Solution:
    def partition(self, head, x):
        # code here
        lo = Node(2000)
        eq = Node(2500)
        hi = Node(3000)
        tempLo = lo
        tempEq = eq
        tempHi = hi
        temp = head
        while temp:
            if temp.data < x:
                tempLo.next = temp
                tempLo = tempLo.next
            elif temp.data == x:
                tempEq.next = temp
                tempEq = tempEq.next 
            else:
                tempHi.next = temp
                tempHi = tempHi.next
            temp = temp.next
        tempHi.next = None
        if eq.next: 
            if lo.next:
                tempLo.next = eq.next
                tempEq.next = hi.next
            else:
                tempEq.next = hi.next
                return eq.next
        else:
            tempLo.next = hi.next
        return lo.next