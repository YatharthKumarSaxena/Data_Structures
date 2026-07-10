class Solution:
    def rearrangeQueue(self, q):
        #code here 
        st = []
        n = len(q)
        count = 0
        while count!=n//2:
            st.append(q.popleft())
            count += 1
        while count!=n:
            q.append(st[-1])
            st.pop()
            count += 1
        count = 0
        while count!=n//2:
            st.append(q.popleft())
            count += 1
        while count!=n:
            q.append(st[-1])
            q.append(q.popleft())
            st.pop()
            count += 1
        count = 0
        while count!=n:
            st.append(q.popleft())
            count += 1
        while count:
            q.append(st[-1])
            st.pop()
            count -= 1