class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> mem(26, INT_MIN);
        for(int i=0; i<s.length(); i++) {
            int c = s[i] - 'a';
            if(mem[c] == INT_MIN) mem[c] = i;
            else if(mem[c] != INT_MAX) mem[c] = INT_MAX;
        }
        int idx=INT_MAX;        
        for(auto n: mem) {
            if(n != INT_MAX && n != INT_MIN) {
                idx = min(idx, n);
            }
        }
        if(idx != INT_MAX) return idx;
        return -1;
    }
};