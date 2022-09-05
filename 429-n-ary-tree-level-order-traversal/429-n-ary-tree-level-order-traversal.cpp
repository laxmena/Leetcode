/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> result;
    
    void traverse(Node* node, int level) {
        while(result.size() <= level) {
            vector<int> vec;
            result.push_back(vec);
        }
        
        result[level].push_back(node->val);
        for(Node* child: node->children) {
            traverse(child, level+1);
        }
    }
    vector<vector<int>> levelOrder(Node* root) {
        if(root != NULL)
           traverse(root, 0);
        
        return result;
    }
};