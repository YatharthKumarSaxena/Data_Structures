from typing import List

class Solution:
    def findCenter(self, edges: List[List[int]]) -> int:
        a = edges[0][0]
        b = edges[0][1]
        c = edges[1][0]
        d = edges[1][1]
        return a if a == c or a == d else b