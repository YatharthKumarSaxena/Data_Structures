#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    char c;
    unordered_map<char, TrieNode*> children;
    bool isTerminal;

    TrieNode(char c) {
        this->c = c;
        this->isTerminal = false;
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

        for (int i = 0; i < word.size(); i++) {
            if (temp->children.find(word[i]) != temp->children.end()) {
                temp = temp->children[word[i]];
            }
            else {
                TrieNode* newNode = new TrieNode(word[i]);
                temp->children[word[i]] = newNode;
                temp = newNode;
            }
        }

        temp->isTerminal = true;
    }

    bool search(string word) {
        TrieNode* temp = root;

        for (int i = 0; i < word.size(); i++) {
            if (temp->children.find(word[i]) != temp->children.end()) {
                temp = temp->children[word[i]];
            }
            else {
                return false;
            }
        }

        return temp->isTerminal;
    }

    bool startsWith(string prefix) {
        TrieNode* temp = root;

        for (int i = 0; i < prefix.size(); i++) {
            if (temp->children.find(prefix[i]) != temp->children.end()) {
                temp = temp->children[prefix[i]];
            }
            else {
                return false;
            }
        }

        return true;
    }
};