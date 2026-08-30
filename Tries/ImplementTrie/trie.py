class TrieNode:
    def __init__(self, c=''):
        self.c = c
        self.children = {}
        self.isTerminal = False


class Trie:

    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        temp = self.root

        for ch in word:
            if ch not in temp.children:
                temp.children[ch] = TrieNode(ch)

            temp = temp.children[ch]

        temp.isTerminal = True

    def search(self, word):
        temp = self.root

        for ch in word:
            if ch not in temp.children:
                return False

            temp = temp.children[ch]

        return temp.isTerminal

    def startsWith(self, prefix):
        temp = self.root

        for ch in prefix:
            if ch not in temp.children:
                return False

            temp = temp.children[ch]

        return True