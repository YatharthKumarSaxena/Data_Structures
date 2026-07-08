class Solution:
    def prevSmaller(self, arr):
        # code here
        n = len(arr)
        st = []
        ans = [-1] * n

        st.append(arr[0])

        for i in range(1, n):
            while len(st) and arr[i] <= st[-1]:
                st.pop()

            if len(st):
                ans[i] = st[-1]

            st.append(arr[i])

        return ans