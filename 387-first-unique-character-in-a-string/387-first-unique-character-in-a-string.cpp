class Solution {
public:
    int firstUniqChar(string s) {
        int hist[26] = {0};
        int order[26] = {0};
                
        for(int i=0; i<s.length(); i++) {
            int idx = s[i] - 'a';
            hist[idx] += 1;
            if(order[idx] == 0) {
                order[idx] = i+1;
            }
        }
        
        int pos = INT_MAX;
        for(int i=0; i<26; i++) {
            if(hist[i] == 1) {
                pos = min(order[i]-1, pos);
            }
        }
        
        return pos == INT_MAX? -1: pos;
    }
};