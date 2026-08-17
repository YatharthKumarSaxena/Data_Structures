class Solution:
    def doBackTrack(self, s, helper, ans):
        n = len(s)

        if n == 0:
            ans.append(helper)
            return

        for i in range(n):
            rem = s[:i] + s[i+1:]

            helper += s[i]

            self.doBackTrack(rem, helper, ans)

            helper = helper[:-1]

    def permutation(self, s):
        ans = []

        self.doBackTrack(s, "", ans)

        ans.sort()

        return ans