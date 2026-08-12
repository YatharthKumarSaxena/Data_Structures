class Solution1:
    def __init__(self):
        self.dp = {}

    def solve(self, s, wordDict):
        if s in self.dp:
            return self.dp[s]

        if not s:
            return True

        for word in wordDict:
            if s[:len(word)] == word:

                remaining = s[len(word):]

                if self.solve(remaining, wordDict):
                    self.dp[s] = True
                    return True

        self.dp[s] = False
        return False

    def wordBreak(self, s, wordDict):
        return self.solve(s, wordDict)


class Solution2:
    def __init__(self):
        self.dp = []

    def doDP(self, i, s, dictionary, lengths):
        if i == len(s):
            return True

        if self.dp[i] != -1:
            return self.dp[i]

        for length in lengths:

            if i + length > len(s):
                continue

            word = s[i:i + length]

            if word in dictionary:
                if self.doDP(i + length, s, dictionary, lengths):
                    self.dp[i] = 1
                    return True

        self.dp[i] = 0
        return False

    def wordBreak(self, s, dictionary):
        self.dp = [-1] * len(s)

        dictionary = set(dictionary)
        lengths = set(len(word) for word in dictionary)

        return self.doDP(0, s, dictionary, lengths)