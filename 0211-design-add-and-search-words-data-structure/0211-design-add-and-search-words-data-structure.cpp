class Node {
    public:
        Node* child[26];
        bool end = false;
};

class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root = new Node();  
    }
    
    void addWord(string word) {
        Node* node = root;
        for(char c: word) {
            int ch = c - 'a';
            // cout << c << " " << ch << "\n";
            if(node->child[ch] == NULL) {
                node->child[ch] = new Node();
            }
            node = node->child[ch];
        }
        // cout << "st to true\n";
        node->end = true;        
    }
    
    bool _search(string& word, int idx, Node* node) {
        for(int i=idx; i<word.size(); i++) {
            char c = word[i];
            int ch = c - 'a';
            
            
            if(c == '.') {
                bool result = false;
                for(int j=0; j<26 && !result; j++) {
                    if(node->child[j] != NULL)
                        result = result || _search(word, i+1, node->child[j]);
                }
                // cout << "returning result " << (result?"True":"False") << endl;
                return result;
            } else {
                if(node->child[ch] == NULL) 
                    return false;
                node = node->child[ch];
            }
            
        }
        return node->end;
    }
    
    bool search(string word) {
        return _search(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */