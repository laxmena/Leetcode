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
    void inorder(TreeNode* root, int k, vector<int>& res) {
        if(!root) return;
        if(res.size() >= k) return;
        
        if(root->left) inorder(root->left, k, res);
        res.push_back(root->val);
        if(root->right) inorder(root->right, k, res);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        vector<int> res;
        inorder(root, k, res);

        return res[k-1];
    }
};