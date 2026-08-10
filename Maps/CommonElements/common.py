class Solution:
    def commonElements(self, a, b):
        mp = {}
        ans = []

        # Frequency of elements in a
        for x in a:
            mp[x] = mp.get(x, 0) + 1

        # Check elements of b
        for x in b:
            if mp.get(x, 0) > 0:
                ans.append(x)
                mp[x] -= 1

        # Sorted order
        ans.sort()

        return ans