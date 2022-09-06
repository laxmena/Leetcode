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
    int sum=0;
    int traverse(TreeNode* root,bool val)
    {
        if(root==NULL)
        {
            return sum;
        }
        traverse(root->left,true);
        traverse(root->right,false);
        if(root->left==NULL && root->right==NULL && val==true)
        {
            sum=sum+root->val;
        }
        return sum;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        bool flag=false;
        traverse(root,flag);
        return sum;
    }
};