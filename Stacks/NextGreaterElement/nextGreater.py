class Solution:
    def nextLargerElement(self, arr):
        # code here
        n = len(arr)
        st = []
        ans = [-1] * n
        st.append(arr[n-1])
        for i in range(n-2,-1,-1):
            while len(st) and arr[i]>=st[-1]: st.pop()
            if len(st): ans[i]=st[-1]
            st.append(arr[i])
        return ans