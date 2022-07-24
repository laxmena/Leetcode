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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        int level = 0;
        
        deque<TreeNode*> q;
        if(root) q.push_back(root);
        
        while(q.empty() == false) {
            int size = q.size();
            result.push_back(vector<int>());
            for(int i=0; i<size; i++) {
                TreeNode* node = q.front();
                
                if(node->left) q.push_back(node->left);
                if(node->right) q.push_back(node->right);
                
                if(level%2 == 0) {
                    result[level].push_back(node->val);
                } else {
                    result[level].insert(begin(result[level]), node->val);
                }
                
                q.pop_front();                                
            }
            level++;
        }
        
        return result;
    }
};