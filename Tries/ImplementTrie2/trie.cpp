#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    char c;
    unordered_map<char, TrieNode*> children;

    int prefixCount;
    int endCount;

    TrieNode(char c) {
        this->c = c;
        this->prefixCount = 0;
        this->endCount = 0;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    void insert(string word) {
        TrieNode* temp = root;

        for (char ch : word) {

            if (temp->children.find(ch) == temp->children.end()) {
                temp->children[ch] = new TrieNode(ch);
            }

            temp = temp->children[ch];

            temp->prefixCount++;
        }

        temp->endCount++;
    }

    int countWordsEqualTo(string word) {
        TrieNode* temp = root;

        for (char ch : word) {

            if (temp->children.find(ch) == temp->children.end()) {
                return 0;
            }

            temp = temp->children[ch];
        }

        return temp->endCount;
    }

    int countWordsStartingWith(string prefix) {
        TrieNode* temp = root;

        for (char ch : prefix) {

            if (temp->children.find(ch) == temp->children.end()) {
                return 0;
            }

            temp = temp->children[ch];
        }

        return temp->prefixCount;
    }

    void erase(string word) {
        TrieNode* temp = root;

        for (char ch : word) {
            temp = temp->children[ch];
            temp->prefixCount--;
        }

        temp->endCount--;
    }
};