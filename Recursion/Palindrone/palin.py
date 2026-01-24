class Solution:
    def checkPalindrome(self, s, start, end):
        if start >= end:
            return True
        if s[start] != s[end]:
            return False
        return self.checkPalindrome(s, start + 1, end - 1)

    def isPalindrome(self, n):
        s = str(n)
        return self.checkPalindrome(s, 0, len(s) - 1)
