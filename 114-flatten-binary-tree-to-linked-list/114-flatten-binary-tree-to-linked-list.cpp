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
    TreeNode* flat(TreeNode* node) {
        if(!node) return NULL;
        TreeNode *left, *right;
        left = flat(node->left);
        node->left = NULL;
        right = flat(node->right);
        if(left != NULL) {
            node->right = left;
            while(left->right != NULL) left=left->right;
        } else {
            left = node;
        }
        left->right = right;
        return node;
    }
    
    void flatten(TreeNode* root) {
        TreeNode* temp = flat(root);
    }
};