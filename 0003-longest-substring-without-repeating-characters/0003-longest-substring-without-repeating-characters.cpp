class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> idxmap;
        int len = 0, start = 0;
        for(int i=0; i<s.size(); i++) {
            if(idxmap.count(s[i]) != 0 && idxmap[s[i]] >= start) {
                int size = i - start;
                len = max(len, size);
                start = idxmap[s[i]]+1;
            }
            idxmap[s[i]] = i;
        }
        
        return max(len, (int)s.size()-start);
    }
};