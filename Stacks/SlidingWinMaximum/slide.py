from typing import List

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)

        # Next Greater Element (index)
        nge = [n] * n
        st = []

        for i in range(n - 1, -1, -1):
            while st and nums[st[-1]] <= nums[i]:
                st.pop()

            if st:
                nge[i] = st[-1]

            st.append(i)

        ans = []
        j = 0

        for i in range(n - k + 1):
            if j < i:
                j = i

            while nge[j] < i + k:
                j = nge[j]

            ans.append(nums[j])

        return ans