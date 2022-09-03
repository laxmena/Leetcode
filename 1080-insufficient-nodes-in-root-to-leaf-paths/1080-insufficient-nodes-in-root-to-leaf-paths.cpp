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
    int limitVal;
    
    bool traverse(TreeNode* node, int sum) {
        // when leaf node is reached, return false if the sum is less than limit
        if(node == NULL) return sum >= limitVal;
        
        bool left = traverse(node->left, sum+(node->val));        
        bool right = traverse(node->right, sum+(node->val));
        
        
        int result = left | right;
        
        if(node->left == NULL && right == false) result = false;
        if(node->right == NULL && left == false) result = false;
           
        if(!left) node->left = NULL;
        if(!right) node->right = NULL;        
        
        return result;
    } 
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        limitVal = limit;
        bool res = traverse(root, 0);
        return res? root: NULL;
    }
};