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
    void flatten(TreeNode* root) {
        TreeNode *head = nullptr, *curr = root;
        while (head != root) {
            if (curr->right == head) curr->right = nullptr;
            if (curr->left == head) curr->left = nullptr;
            if (curr->right) curr = curr->right;
            else if (curr->left) curr = curr->left;
            else curr->right = head, head = curr, curr = root;
        }
    }
};