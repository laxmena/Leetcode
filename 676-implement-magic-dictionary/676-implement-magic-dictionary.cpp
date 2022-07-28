class MagicDictionary {
public:
    vector<string> dict;
    MagicDictionary() {
    }
    
    void buildDict(vector<string> dictionary) {
        dict.insert(end(dict), begin(dictionary), end(dictionary));
    }
    
    bool search(string searchWord) {
        for(string word: dict) {
            if(word.size() != searchWord.size()) 
                continue;
            int miss = 0;
            for(int i=0; i<word.size() && miss < 2; i++) {
                if(word[i] != searchWord[i]) miss++;
            }
            if(miss == 1) return true;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */