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
    void traverse(TreeNode* node, int level, vector<vector<int> > *res) {
        if(!node) return;
        if(level == res->size()) {
            vector<int> vec;
            res->push_back(vec);
        }
        (res->at(level)).push_back(node->val);
        if(node->left) traverse(node->left, level+1, res);
        if(node->right) traverse(node->right, level+1, res);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > res;
        traverse(root, 0, &res);
        return res;
    }
};