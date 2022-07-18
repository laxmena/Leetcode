/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    
    Node* lowestCommonAncestor(Node* p, Node * q) {
        set<Node*> visited;
        Node* parent = p;
        while(parent) {
            visited.insert(parent);
            parent = parent->parent;
        }
        parent = q;
        while(parent) {
            if(visited.count(parent) != 0)
                return parent;
            else parent = parent->parent;
        }
        return NULL;
    }
};