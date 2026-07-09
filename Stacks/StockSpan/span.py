class Solution:
    def calculateSpan(self, arr):
        # code here
        n = len(arr)
        ans = [1]*n
        st = []
        st.append(0)
        for i in range(1,n):
            while len(st) and arr[i]>=arr[st[-1]]: st.pop()
            if len(st): ans[i]=i-st[-1]
            else: ans[i] = i+1
            st.append(i)
        return ans