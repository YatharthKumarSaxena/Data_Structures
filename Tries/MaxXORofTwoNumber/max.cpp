#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* children[2];

    TrieNode() {
        children[0] = nullptr;
        children[1] = nullptr;
    }
};

class Solution {
public:

    void insert(TrieNode* root, int num) {

        TrieNode* temp = root;

        for (int i = 31; i >= 0; i--) {

            int bit = (num >> i) & 1;

            if (temp->children[bit] == nullptr) {
                temp->children[bit] = new TrieNode();
            }

            temp = temp->children[bit];
        }
    }

    int getMaxXOR(TrieNode* root, int num) {

        TrieNode* temp = root;
        int ans = 0;

        for (int i = 31; i >= 0; i--) {

            int bit = (num >> i) & 1;

            // Opposite bit gives 1 in XOR
            int opposite = 1 - bit;

            if (temp->children[opposite] != nullptr) {
                ans |= (1 << i);
                temp = temp->children[opposite];
            }
            else {
                temp = temp->children[bit];
            }
        }

        return ans;
    }

    int findMaximumXOR(vector<int>& nums) {

        TrieNode* root = new TrieNode();

        // Insert all numbers
        for (int num : nums) {
            insert(root, num);
        }

        int ans = 0;

        // Find best XOR for every number
        for (int num : nums) {
            ans = max(ans, getMaxXOR(root, num));
        }

        return ans;
    }
};