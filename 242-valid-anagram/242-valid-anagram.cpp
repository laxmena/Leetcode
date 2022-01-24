class Solution {
public:
    bool isAnagram(string s, string t) {
        int freq[26] = {0};
        for(auto c: s) freq[c - 'a']++;
        for(auto c: t) freq[c - 'a']--;
        for(auto n: freq) {
            if(n != 0) return false;
        }
        return true;
    }
};