class MyCircularDeque:

    def __init__(self, k: int):
        self.arr = [0] * (k+1)
        self.front = 0
        self.back = 0

    def insertFront(self, value: int) -> bool:
        if self.isFull(): return False
        self.front = (self.front - 1 + len(self.arr)) % len(self.arr)
        self.arr[self.front] = value
        return True

    def insertLast(self, value: int) -> bool:
        if self.isFull(): return False
        self.arr[self.back] = value
        self.back = (self.back+1)%len(self.arr)
        return True


    def deleteFront(self) -> bool:
        if self.isEmpty(): return False
        self.front = (self.front+1)%len(self.arr)
        return True

    def deleteLast(self) -> bool:
        if self.isEmpty(): return False
        self.back = (self.back - 1 + len(self.arr)) % len(self.arr)
        return True

    def getFront(self) -> int:
        if self.isEmpty(): return -1 
        return self.arr[self.front]

    def getRear(self) -> int:
        if self.isEmpty(): return -1 
        idx = self.back-1
        return self.arr[idx]

    def isEmpty(self) -> bool:
        return self.front == self.back

    def isFull(self) -> bool:
        return (self.back+1)%len(self.arr) == self.front


# Your MyCircularDeque object will be instantiated and called as such:
# obj = MyCircularDeque(k)
# param_1 = obj.insertFront(value)
# param_2 = obj.insertLast(value)
# param_3 = obj.deleteFront()
# param_4 = obj.deleteLast()
# param_5 = obj.getFront()
# param_6 = obj.getRear()
# param_7 = obj.isEmpty()
# param_8 = obj.isFull()