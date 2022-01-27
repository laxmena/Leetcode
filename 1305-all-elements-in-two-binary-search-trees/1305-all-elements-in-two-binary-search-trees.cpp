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
    void vectorize(TreeNode* root, vector<int> *result) {
        if(!root) return;
        result->push_back(root->val);
        if(root->left) vectorize(root->left, result);
        if(root->right) vectorize(root->right, result);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> result;
        vectorize(root1, &result);
        vectorize(root2, &result);
        sort(result.begin(), result.end());
        return result;
    }
};