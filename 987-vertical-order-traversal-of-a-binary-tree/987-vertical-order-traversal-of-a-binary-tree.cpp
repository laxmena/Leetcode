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
    map<int, map<int, vector<int>> > m;

    void traverse(TreeNode* node, int row, int col) {
        if(node == NULL) return;
        m[col][row].push_back(node->val);
        traverse(node->left, row+1, col-1);
        traverse(node->right, row+1, col+1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        traverse(root, 0, 0);
        
        for(auto const& col: m) {
            vector<int> merge, temp;
            for(auto const& row: col.second) {
                temp = row.second;
                sort(begin(temp), end(temp));
                merge.insert(end(merge), begin(temp), end(temp));
            }
            result.push_back(merge);
        }
        
        return result;
    }
};