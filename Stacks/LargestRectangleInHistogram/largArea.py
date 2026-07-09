from typing import List

class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        n = len(heights)
        pse = [-1] * n
        nse = [n] * n
        st1, st2 = [0], [n-1]
        for i in range(1,n):
            while len(st1) and heights[i]<=heights[st1[-1]]: st1.pop()
            if len(st1): pse[i] = st1[-1]
            st1.append(i)
        for i in range(n-2,-1,-1):
            while len(st2) and heights[i]<=heights[st2[-1]]: st2.pop()
            if len(st2): nse[i] = st2[-1]
            st2.append(i)
        maxArea = 0
        for i in range(n):
            height = heights[i]
            breadth = nse[i] - pse[i] - 1
            area = height*breadth
            maxArea = max(maxArea,area)
        return maxArea