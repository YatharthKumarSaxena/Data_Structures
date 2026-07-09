from typing import List

class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        n = len(prices)
        st = []
        ans = prices[:]
        st.append(prices[n-1])
        for i in range(n-2,-1,-1):
            while len(st) and prices[i]<st[-1]: st.pop()
            if len(st): ans[i]=prices[i]-st[-1]
            st.append(prices[i])
        return ans