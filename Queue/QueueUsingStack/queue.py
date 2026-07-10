class MyQueue1:

    def __init__(self):
        self.st = []

    def push(self, x: int) -> None:
        helper = []
        while len(self.st) != 0:
            val = self.st[-1]
            self.st.pop()
            helper.append(val)
        self.st.append(x)
        while len(helper) != 0:
            val = helper[-1]
            helper.pop()
            self.st.append(val)

    def pop(self) -> int:
        val = self.st[-1]
        self.st.pop()
        return val

    def peek(self) -> int:
        return self.st[-1]

    def empty(self) -> bool:
        return len(self.st)==0


# Your MyQueue object will be inself.stantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()


class MyQueue2:

    def __init__(self):
        self.st = []

    def push(self, x: int) -> None:
        self.st.append(x)

    def pop(self) -> int:
        helper = []
        while len(self.st) != 1:
            val = self.st[-1]
            self.st.pop()
            helper.append(val)
        ans = self.st[-1]
        self.st.pop()
        while len(helper) != 0:
            val = helper[-1]
            helper.pop()
            self.st.append(val)
        return ans

    def peek(self) -> int:
        helper = []
        while len(self.st) != 1:
            val = self.st[-1]
            self.st.pop()
            helper.append(val)
        ans = self.st[-1]
        while len(helper) != 0:
            val = helper[-1]
            helper.pop()
            self.st.append(val)
        return ans

    def empty(self) -> bool:
        return len(self.st)==0


# Your MyQueue object will be inself.stantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()