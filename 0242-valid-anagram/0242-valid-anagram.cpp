class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> hist(26, 0);
        for(char c: s) hist[c-'a']++;
        for(char c: t) hist[c-'a']--;
        for(int i: hist) if(i != 0) return false;
        return true;
    }
};