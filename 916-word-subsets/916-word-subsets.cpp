class Solution {
public:
    vector<int> getDist(string word) {
        vector<int> freq(26,0);
        for(char c: word) freq[c-'a']++;
        return freq;
    }
    
    bool isUniversal(vector<int> word, vector<int> target) {
        for(int i=0; i<26; i++) {
            if(target[i] > word[i]) return false;
        }
        return true;
    }
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> result;
        vector<int> tgt(26,0);
        for(string word: words2) {
            vector<int> temp = getDist(word);
            for(int i=0; i<26; i++) 
                tgt[i] = max(tgt[i], temp[i]);
        }
        
        for(string word: words1) {
            vector<int> temp = getDist(word);
            if(isUniversal(temp, tgt))
                result.push_back(word);
        }
        
        return result;
    }
};