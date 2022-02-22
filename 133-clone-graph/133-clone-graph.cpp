/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        
        if(!node) return node;
        
        map<Node*, Node*> m;
        deque<Node*> q;
        q.push_back(node);
        
        while(!q.empty()) {
            Node* cur = q.front();
            q.pop_front();
            if(!cur) continue;            
            if(m.count(cur)) continue;
            
            Node* newNode = new Node(cur->val, cur->neighbors);
            m[cur] = newNode;

            for(auto n: cur->neighbors) {
                if(m.count(n) == 0)  q.push_back(n);
            }
        }
        
        for(auto& [oldn, newn]: m) {
            vector<Node*>& neighbors = newn->neighbors;
            for(int i=0; i<neighbors.size(); i++) {
                neighbors[i] = m[neighbors[i]];
            }
        }
        
        return m[node];
    }
};