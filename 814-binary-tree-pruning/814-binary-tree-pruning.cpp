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
    int traverse(TreeNode* root) {
        if(root == NULL) return 0;
        int left = traverse(root->left);
        int right = traverse(root->right);
        if(left == 0) root->left = NULL;
        if(right == 0) root->right = NULL;
        return root->val + left + right;
    }
    TreeNode* pruneTree(TreeNode* root) {
        int val = traverse(root);
        return (val == 0)? NULL: root;
    }
};