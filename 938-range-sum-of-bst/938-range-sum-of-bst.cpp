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
    int result = 0, temp;
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;
        if(root->val >= low && root->val <= high) result += root->val;

        if(root->val > high) 
            temp = rangeSumBST(root->left, low, high);
        else if(root->val <= low) temp = rangeSumBST(root->right, low, high);
        else {
            temp = rangeSumBST(root->left, low, high);
            temp = rangeSumBST(root->right, low, high);
        }
        
        return result;
    }
};