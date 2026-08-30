class TrieNode:
    def __init__(self, c=''):
        self.c = c
        self.children = {}
        self.prefixCount = 0
        self.endCount = 0


class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        temp = self.root

        for ch in word:

            if ch not in temp.children:
                temp.children[ch] = TrieNode(ch)

            temp = temp.children[ch]
            temp.prefixCount += 1

        temp.endCount += 1

    def countWordsEqualTo(self, word):
        temp = self.root

        for ch in word:

            if ch not in temp.children:
                return 0

            temp = temp.children[ch]

        return temp.endCount

    def countWordsStartingWith(self, prefix):
        temp = self.root

        for ch in prefix:

            if ch not in temp.children:
                return 0

            temp = temp.children[ch]

        return temp.prefixCount

    def erase(self, word):
        temp = self.root

        for ch in word:
            temp = temp.children[ch]
            temp.prefixCount -= 1

        temp.endCount -= 1