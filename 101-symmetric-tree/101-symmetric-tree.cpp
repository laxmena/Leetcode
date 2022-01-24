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
    bool checkSymmetry(TreeNode* left, TreeNode* right) {
        if(left == NULL && right == NULL) return true;
        if(!left || !right) return false;
        if(left->val != right->val) return false;
        bool l = checkSymmetry(left->left, right->right);
        bool r = checkSymmetry(left->right, right->left);
        return l & r;
    }
    
    bool isSymmetric(TreeNode* root) {
        return checkSymmetry(root->left, root->right);    
    }
};