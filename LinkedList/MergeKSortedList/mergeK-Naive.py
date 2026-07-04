'''
class Node:
    def _init_(self, x):
        self.data = x
        self.next = None
'''

class Solution:
        # code here
        def mergeTwoLists(self, list1, list2):
            ans = None
            a = list1
            b = list2
    
            if a==None: return b
            if b==None: return a
    
            if a.data < b.data:
                ans = a
                a = a.next
    
            else:
                ans = b
                b = b.next
            
            temp = ans
            while a and b:
                if a.data < b.data:
                    temp.next = a
                    a = a.next
                else:
                    temp.next = b
                    b = b.next        
                temp = temp.next
    
            if b: temp.next = b
            if a: temp.next = a
            return ans
        def mergeKLists(self, arr):
            n = len(arr)
            if n==0: return None
            while n > 1:
                list1 = arr[n-1]
                arr.pop()
                n -= 1
                list2 = arr[n-1]
                arr.pop()
                mergeList = self.mergeTwoLists(list1,list2)
                arr.append(mergeList)
            return arr[0]