#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* first = NULL;
    typedef pair<TreeNode*,int> plp;
    void makeParentPair(unordered_map<TreeNode*,TreeNode*>& parent,TreeNode* root){
        if(!root)return;
        if(root->left)parent[root->left] = root;
        if(root->right)parent[root->right] = root;
        makeParentPair(parent,root->left);
        makeParentPair(parent,root->right);
    }
    void findStartNode(TreeNode* root, int start){
        if(!root)return;
        if(root->val == start){
            first = root;
            return;
        }
        findStartNode(root->left,start);
        findStartNode(root->right,start);
    }

    int amountOfTime(TreeNode* root, int start) {
        findStartNode(root,start);
        unordered_set<TreeNode*> isInfected;
        unordered_map<TreeNode*,TreeNode*> parent;
        makeParentPair(parent,root);
        queue<plp>qu;
        qu.push({first,0});
        int totalTime = 0;
        while(!qu.empty()){
            plp levelNode = qu.front();
            TreeNode* node = levelNode.first;
            totalTime = levelNode.second;
            if(isInfected.find(node)==isInfected.end()){
                int nextLevel = totalTime+1;
                isInfected.insert(node);
                if(parent.find(node)!=parent.end()){
                    if(isInfected.find(parent[node])==isInfected.end()){
                        qu.push({parent[node],nextLevel});
                    }
                }
                if(node->left){
                    if(isInfected.find(node->left)==isInfected.end()){
                        qu.push({node->left,nextLevel});
                    }
                }
                if(node->right){
                    if(isInfected.find(node->right)==isInfected.end()){
                        qu.push({node->right,nextLevel});
                    }
                }
            }
            qu.pop();
        }
        return totalTime;
    }
};