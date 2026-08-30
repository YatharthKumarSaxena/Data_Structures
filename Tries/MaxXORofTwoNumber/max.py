class TrieNode:
    def __init__(self):
        self.children = [None, None]


class Solution:

    def insert(self, root, num):

        temp = root

        for i in range(31, -1, -1):

            bit = (num >> i) & 1

            if temp.children[bit] is None:
                temp.children[bit] = TrieNode()

            temp = temp.children[bit]

    def getMaxXOR(self, root, num):

        temp = root
        ans = 0

        for i in range(31, -1, -1):

            bit = (num >> i) & 1

            # Opposite bit gives 1 in XOR
            opposite = 1 - bit

            if temp.children[opposite] is not None:
                ans |= (1 << i)
                temp = temp.children[opposite]
            else:
                temp = temp.children[bit]

        return ans

    def findMaximumXOR(self, nums):

        root = TrieNode()

        # Insert all numbers
        for num in nums:
            self.insert(root, num)

        ans = 0

        # Find best XOR for every number
        for num in nums:
            ans = max(ans, self.getMaxXOR(root, num))

        return ans