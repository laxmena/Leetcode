/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* node, int level, vector<int>* res) {
        if(!node) return;
        if(res->size() <= level) {
            res->push_back(node->val);
        } else {
            res->at(level) = node->val;
        }
        if(node->left) dfs(node->left, level+1, res);
        if(node->right) dfs(node->right, level+1, res);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        
        if(!root) return result;
        dfs(root, 0, &result);
        
        return result;
    }
};