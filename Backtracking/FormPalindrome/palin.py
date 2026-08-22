class Solution:

    def checkPalindrome(self, curr):
        temp = curr[::-1]
        return temp == curr

    def doBacktrack(self, n, currLen, curr, ans):

        if currLen == n:
            if self.checkPalindrome(curr):
                ans.append(curr)
            return

        for i in range(10):

            check = (n + 1) // 2

            if currLen < check:
                self.doBacktrack(
                    n,
                    currLen + 1,
                    curr + chr(48 + i),
                    ans
                )

            else:
                if chr(48 + i) == curr[n - 1 - currLen]:
                    self.doBacktrack(
                        n,
                        currLen + 1,
                        curr + chr(48 + i),
                        ans
                    )

    def generatePalindromes(self, n):
        ans = []
        self.doBacktrack(n, 0, "", ans)
        return ans


# Testing
obj = Solution()

testCases = [1, 2, 3, 4, 5]

for n in testCases:

    ans = obj.generatePalindromes(n)

    print("n =", n)
    print("Total Palindromes:", len(ans))

    for s in ans:
        print(s, end=" ")

    print("\n")