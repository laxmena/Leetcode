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
        vector<Node*> created;
        
        Node* head = node;

        stack<Node*> st;
        set<Node*> visited;
        
        st.push(node);        
        
        while(!st.empty()) {
            // cout << st.size() << "\n";
            node = st.top();
            st.pop();

            if(visited.count(node))
                continue;
            visited.insert(node);
            
            Node* newnode = new Node(node->val, node->neighbors);
            created.push_back(newnode);
            m[node] = newnode;

            for(auto& n: node->neighbors) {
                if(!visited.count(n))
                    st.push(n);
            }
        }
        
        for(int i=0; i<created.size(); i++) {
            vector<Node*>& neigh = created[i]->neighbors;
            for(int j=0; j<neigh.size(); j++) {
                neigh[j] = m[neigh[j]];
            }
        }
        
        return m[head];
    }
};