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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result; 
        
        // exit condition: leaf node
        if(root == NULL) return result;
        if(!(root->left) && !(root->right)) {
            if(targetSum == root->val) {
                vector<int> inVec; 
                inVec.push_back(root->val);
                result.push_back(inVec);
                return result;
             }
             return result;
        }
        
        // traverse left subtree
        vector<vector<int>> left = pathSum(root->left, targetSum - root->val);
        // traverse right subtree
        vector<vector<int>> right = pathSum(root->right, targetSum - root->val);
        
        for(auto inVec: left) {
            if(inVec.size() == 0) continue;
            inVec.insert(inVec.begin(), 1, root->val);
            result.push_back(inVec);
        }
        for(auto inVec: right) {
            if(inVec.size() == 0) continue;
            inVec.insert(inVec.begin(), 1, root->val);
            result.push_back(inVec);
        }
        return result;
    }
    
};