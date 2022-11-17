class Node {
    public:
        Node* child[26];
        bool end = false;
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        if(!root) return;
        Node* node = root;
        for(char c: word) {
            if(node->child[c-'a'] == NULL) {
                node->child[c-'a'] = new Node();
            }
            node = node->child[c-'a'];
        }
        node->end = true;
    }
    
    bool search(string word) {
        Node* node = root;
        for(char c: word) {
            if(node->child[c-'a'] == NULL) return false;
            node = node->child[c-'a'];
        }
        return node->end;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(char c: prefix) {
            if(node->child[c-'a'] == NULL) return false;
            node = node->child[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */