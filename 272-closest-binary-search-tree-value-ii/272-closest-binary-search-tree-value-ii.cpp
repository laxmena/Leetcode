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
typedef pair<double, int> pi;
typedef priority_queue<pi> pq;

class Solution {
public:
    void inorder(TreeNode* root, double& target, pq& heap, int k) {
        if(!root) return;
        double diff = abs(target - (root->val));
        // cout << "Diff: " << diff << " | val: " << root->val << "\n";
        heap.push(make_pair(diff, root->val));
        if(heap.size() > k) heap.pop();
        inorder(root->left, target, heap, k);
        inorder(root->right, target, heap, k);
    }
    
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        pq heap;
        
        inorder(root, target, heap, k);

        vector<int> result;
        while(!heap.empty()) {
            result.push_back(heap.top().second);
            heap.pop();
        }
        return result;
    }
};