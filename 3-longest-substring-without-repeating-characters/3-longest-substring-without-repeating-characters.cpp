class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() < 2) return s.length();
        vector<int> mem(256, INT_MIN);
        int start = 0;
        mem[s[0]] = 0;
        int len = 1;
        for(int i=1; i<s.length(); i++) {
            if(mem[s[i]] >= start) start = mem[s[i]] + 1;
            len = max(len, i-start+1);
            mem[s[i]] = i;
        }
        return len;
    }
};