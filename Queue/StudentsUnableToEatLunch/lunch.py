from typing import List
from collections import deque

class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        qu = deque()
        n = len(students)
        for i in range(n):
            qu.append(students[i])
        j = 0
        count = 0
        while j<n and count != len(qu):
            x = qu.popleft()
            if x == sandwiches[j]:
                j += 1
                count = 0
            else:
                qu.append(x)
                count += 1
        return count