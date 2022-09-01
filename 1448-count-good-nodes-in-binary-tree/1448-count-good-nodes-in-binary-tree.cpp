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
    int iterate(TreeNode* node, int maxVal) {
        int result = 0;
        if(node->val >= maxVal) {
            maxVal = node->val;
            result += 1;
        }
        
        if(node->left) result += iterate(node->left, maxVal);
        if(node->right) result += iterate(node->right, maxVal);
        
        return result;
    }

    int goodNodes(TreeNode* root) {
        return iterate(root, INT_MIN);        
    }
};