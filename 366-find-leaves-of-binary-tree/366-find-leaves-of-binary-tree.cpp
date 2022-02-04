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
    int traverse(TreeNode* root, vector<vector<int> > &result) {
        if(root == NULL) {return -1; }
        int level = max(traverse(root->left, result), traverse(root->right, result)) + 1;
        if(result.size() <= level) {
            vector<int> res;
            result.push_back(res);
        }
        result[level].push_back(root->val);
        return level;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int> > result;
        traverse(root, result);
        return result;
    }
};