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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<vector<int>> bfs;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()) {
            int n = q.size();
            vector<int> lvec;
            for(int i=0; i<n; i++) {
                TreeNode* node = q.front();
                lvec.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                q.pop();
            }
            bfs.push_back(lvec);
        }
        vector<double> result;
        for(auto v: bfs) {
            long long sum = 0;
            for(auto s: v) sum += s;
            result.push_back((double)sum/v.size());
        }
        return result;
    }
};