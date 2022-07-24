class Solution {
public:
    bool compare(string word, string target) {
        if(target.size() < word.size()) return false;
        int len = target.size();
        
        
        for(int i=0; i<len; i++) {
            if(word[i] != target[i]) return false;
            
        }

        return true;
    }
    
    int isPrefixOfWord(string sentence, string target) {
        string word = "";
        int wordCount = 0;
        
        for(int i=0; i<sentence.size(); i++) {
            
            if(word.size() == target.size()) {
                if(compare(word, target)) return wordCount;
            } 
            
            if(i == 0 || sentence[i] == ' ') {
                wordCount += 1;
                word ="";
            }
            if(sentence[i] != ' ') word += sentence[i];            
        }
        
        return compare(word, target)?wordCount: -1;
    }
};