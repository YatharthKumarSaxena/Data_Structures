class Solution:
    def doBackTrack(self, idx, helper, ans):
        n = len(helper)

        if idx == n:
            ans.append(helper)
            return

        # Keep current character as it is
        self.doBackTrack(idx + 1, helper, ans)

        # If character is alphabet
        if not ('0' <= helper[idx] <= '9'):

            # Lowercase -> Uppercase
            if 'a' <= helper[idx] <= 'z':
                helper = helper[:idx] + helper[idx].upper() + helper[idx + 1:]

                self.doBackTrack(idx + 1, helper, ans)

            # Uppercase -> Lowercase
            else:
                helper = helper[:idx] + helper[idx].lower() + helper[idx + 1:]

                self.doBackTrack(idx + 1, helper, ans)

    def letterCasePermutation(self, s):
        ans = []

        self.doBackTrack(0, s, ans)

        return ans