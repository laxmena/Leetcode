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
    map<int, map<int,vector<int>>> mp;
    void dfs(TreeNode* root, int row, int col) {
        if(root == NULL) {
            return ;
        }
        
        mp[col][row].push_back(root->val);
        
        dfs(root->left, row+1, col-1);
        dfs(root->right, row+1, col+1);
    }
    vector<vector<int>> verticalOrder(TreeNode* root) {
        dfs(root, 0, 0);
        
        //now convert map into answer format vector of vector
        vector<vector<int>> ans;
        for(auto m1 : mp) {
            vector<int> a;
            for(auto m2 : m1.second) {
                for(auto x : m2.second) {
                    a.push_back(x);
                }
            }
            ans.push_back(a);
        }
        
        return ans;
    }
};