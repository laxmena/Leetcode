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
    int maxVal;
    
    int traverse(TreeNode* node) {
        if(!node) return 0;
        int val = node->val;
        int left = traverse(node->left) + val;
        int right = traverse(node->right) + val;
        int bothchild = left + right - val;
        
        int retVal = max(max(left, right), max(val, bothchild));
        maxVal = max(maxVal, retVal);
        
        return max(max(left, right), val);
    }
    
    int maxPathSum(TreeNode* root) {
        maxVal = root->val;
        traverse(root);                
        return maxVal;
    }
};