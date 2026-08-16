class Solution:
    def minOperations(self, arr: list[int]) -> int:
        st = set()

        for x in arr:
            if x:
                st.add(x)

        return len(st)