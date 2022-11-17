/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool isPresent(TreeNode* node, TreeNode* s) {
        if(!node) return false;
        if(node == s) return true;
        if(node->val > s->val) return isPresent(node->left, s);
        else return isPresent(node->right, s);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        if(root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        
        // 3 cases -> p is on the root node, or q is on the root node, or p and q are in either subtrees
        // In either of these cases, we just need to find if the nodes are there, as this will be the lowest common ancestor
        if(isPresent(root, p) && isPresent(root, q)) {
            return root;
        }
        return NULL;
    }
};