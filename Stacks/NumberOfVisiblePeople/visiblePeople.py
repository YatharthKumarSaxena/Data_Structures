from typing import List

def canSeePersonsCount(self, heights: List[int]) -> List[int]:
    n = len(heights)
    ans = [0] * n
    st = [heights[n - 1]]

    for i in range(n - 2, -1, -1):
        count = 0

        while len(st) and heights[i] >= st[-1]:
            st.pop()
            count += 1

        if len(st):
            count += 1

        ans[i] = count
        st.append(heights[i])

    return ans