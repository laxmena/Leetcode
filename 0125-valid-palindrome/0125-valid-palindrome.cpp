class Solution {
public:
    bool isPalindrome(string s) {
        string s1 = "";
        for(char c: s) {
            if(c >= 'a' && c <= 'z') s1 += c;
            if(c >= 'A' && c <= 'Z') s1 += char(c+32);
            if(c >= '0' && c <= '9') s1 += c;
        }
        for(int i=0; i<s1.size()/2; i++)
            if(s1[i] != s1[s1.size()-i-1]) return false;
        return true;
    }
};