/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    pair<Node*, Node*> traverse(Node* node) {
        if(!(node->left) && !(node->right)) return make_pair(node, node);
        pair<Node*, Node*> left, right;
        if(node->left) {
            left = traverse(node->left);
            left.second->right = node;
            node->left = left.second;
        } else {
            left = make_pair(node, node);
        }
        if(node->right) {
            right = traverse(node->right);
            node->right = right.first;
            right.first->left = node;
        } else {
            right = make_pair(node, node);
        }
        return make_pair(left.first, right.second);
    }
    
    Node* treeToDoublyList(Node* root) {
        if(!root) return root;
        pair<Node*, Node*> leftright = traverse(root);
        leftright.first->left = leftright.second;
        leftright.second->right = leftright.first;
        return leftright.first;
    }
};