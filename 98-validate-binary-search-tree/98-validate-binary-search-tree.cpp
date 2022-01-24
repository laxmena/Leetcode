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
    bool check(TreeNode* root, long min, long max) {
        if(!root) return true;
        if(root->val >= max || root->val <= min) return false;
        return check(root->left, min, root->val) && check(root->right, root->val, max);
    }
    bool isValidBST(TreeNode* root) {
        return check(root, (long)INT_MIN-1, (long)INT_MAX+1);
    }
};