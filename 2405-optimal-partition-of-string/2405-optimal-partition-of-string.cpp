class Solution {
public:
    int partitionString(string s) {
        int result = 0;
        int prev = -2;
        vector<int> freq(26, -1);
        
        for(int i=0; i<s.size(); i++) {
            int ch = s[i] - 'a';
            if(freq[ch] > prev) {
                result++;
                prev = i-1;
            }
            freq[ch] = i;
        }
        
        return result;
    }
};