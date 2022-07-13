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
    void recurse(TreeNode* node, vector<vector<int>>& result, int level = 0) {
        if(!node) return;
        if(result.size() <= level) {
            vector<int> levelResult;
            result.push_back(levelResult);
        }
        result[level].push_back(node->val);
        recurse(node->left, result, level+1);
        recurse(node->right, result, level+1);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;        
        recurse(root, result);
        return result;
    }
};