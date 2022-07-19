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
    map<long, long> sums;
    void traverse(TreeNode* node, vector<long long> prevSums) {
        if(!node) return;
        
        int val = node->val;
        for(int i=0; i<prevSums.size(); i++) {
            prevSums[i] += val;
            sums[prevSums[i]] += 1;
        }
        prevSums.push_back(val);
        sums[val] += 1;
        
        traverse(node->left, prevSums);
        traverse(node->right, prevSums);
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        vector<long long> temp;
        traverse(root, temp);
        return sums[targetSum];
    }
};