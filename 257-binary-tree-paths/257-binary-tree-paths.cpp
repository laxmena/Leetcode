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
    void dfs(TreeNode* root, string prefix, vector<string> &result) {
        if(!root) return;
        if(prefix == "") prefix = to_string(root->val);
        else prefix += "->" + to_string(root->val);
        if(root->left == NULL && root->right == NULL) { result.push_back(prefix); return; }
        if(root->left) dfs(root->left, prefix, result);
        if(root->right) dfs(root->right, prefix, result);
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        dfs(root, "", result);
        return result;
    }
};