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
    
    int findPosition(vector<int> vec, int target) {
        for(int i=0; i<vec.size(); i++) {
            if(vec[i] == target) return i;
        }
        return -1;
    }
    
    vector<int> slice(vector<int> vec, int start, int end) {
        vector<int> result;
        for(int i=start; i<end; i++) {
            result.push_back(vec[i]);
        }
        return result;
    }
        
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0) return NULL;
        // First element of preorder traversal is the root node
        
        int pos = findPosition(inorder, preorder[0]);
        
        vector<int> leftPreorder = slice(preorder, 1, pos+1);
        vector<int> leftInorder = slice(inorder, 0, pos);

        TreeNode* leftNode = buildTree(leftPreorder, leftInorder);
        vector<int> rightPreorder = slice(preorder, pos+1, preorder.size());
        vector<int> rightInorder = slice(inorder, pos+1, inorder.size());
        
        TreeNode* rightNode = buildTree(rightPreorder, rightInorder);
        
        TreeNode* node = new TreeNode(preorder[0], leftNode, rightNode);
        return node;
    }
};