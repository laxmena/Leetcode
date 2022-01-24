class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int freq[26] = {0};
        for(auto c: ransomNote) freq[c-'a']--;
        for(auto c: magazine) freq[c-'a']++;
        for(auto n: freq) {
            if(n < 0) return false;
        }
        return true;
    }
};