class Solution:
    def dailyTemperatures(self, temperatures):
        n = len(temperatures)
        ans = [0] * n
        st = []

        st.append(n - 1)

        for i in range(n - 2, -1, -1):
            while st and temperatures[i] >= temperatures[st[-1]]:
                st.pop()

            if st:
                ans[i] = st[-1] - i

            st.append(i)

        return ans