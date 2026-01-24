class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1: return "1"
        curr = self.countAndSay(n-1)
        ans = ""
        freq = 1
        for i in range(len(curr)-1):
            character = curr[i]
            if character == curr[i+1]: freq+=1
            else:
                ans += (str(freq)+character)
                freq = 1
        ans += str(freq) + curr[-1]
        return ans

