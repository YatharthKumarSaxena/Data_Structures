class Solution:
    def kthGrammar(self, n: int, k: int) -> int:
        ans = []
        searchEleIdx = 2**(n-1)-1+k
        while searchEleIdx>0:
            ans.append(searchEleIdx)
            searchEleIdx //= 2
        idx = len(ans)
        answer = 0
        curr = 1
        for i in range(idx-2,-1,-1):
            if ans[i] == curr*2+1: 
                if answer == 1:
                    answer = 0
                else:
                    answer = 1
            curr = ans[i]
        return answer

        