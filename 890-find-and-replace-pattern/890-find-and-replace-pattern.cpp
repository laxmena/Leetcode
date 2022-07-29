class Solution {
public:
    string getPattern(string s) {
        string p = "";
        int counter = 0;
        map<char, int> m;
        for(char c: s) {
            if(m.find(c) == m.end()) {
                m[c] = counter++;
            }
            p.push_back(m[c]+'a');
        }
        return p;
    } 
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        map<string, vector<string>> m;
        for(auto word: words) {
            m[getPattern(word)].push_back(word);
        }
        return m[getPattern(pattern)];
    }
};