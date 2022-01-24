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
    void insert(TreeNode* node, int val) {
        if(node->val > val) {
            if(node->left == NULL) {
                node->left = new TreeNode(val);
                return;
            }
            insert(node->left, val);
        }
        else {
            if(node->right == NULL) {
                node->right = new TreeNode(val); return;
            }
            insert(node->right, val);
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        insert(root, val);
        return root;
    }
};