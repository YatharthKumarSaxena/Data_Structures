class Solution:
    def reverseFirstK(self, q, k):
        if k <= 1:
            return q

        n = len(q)

        if k > n:
            return q

        st = []

        for _ in range(k):
            st.append(q.popleft())

        while st:
            q.append(st.pop())

        for _ in range(n - k):
            q.append(q.popleft())

        return q