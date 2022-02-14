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
    int treeHeight(TreeNode* root) {
        if(!root) return 0;
        int left = treeHeight(root->left);
        int right = treeHeight(root->right);
        
        if(left == -1 || right == -1 || abs(left - right)>1) return -1;
        return max(left, right) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return treeHeight(root) != -1;
        
    }
};