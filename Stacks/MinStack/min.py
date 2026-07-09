class MinStack:

    def __init__(self):
        self.helper = []
        self.st = []

    def push(self, value: int) -> None:
        if len(self.st) == 0:
            self.st.append(value)
            self.helper.append(value)
            return
        val = self.helper[-1]
        if val > value:
            self.helper.append(value)
        else:
            self.helper.append(val)
        self.st.append(value)
        return

    def pop(self) -> None:
        if len(self.st)==0: return
        self.st.pop()
        self.helper.pop()
        return
        

    def top(self) -> int:
        return self.st[-1]

    def getMin(self) -> int:
        return self.helper[-1]
    
    

# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(value)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()