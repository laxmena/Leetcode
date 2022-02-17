class Solution {
public:
    int minFlipsMonoIncr(string s) {
        vector<int> zeros(s.size(), 0);
        int minFlips = INT_MAX;

        
        for(int i=1; i<s.size(); i++) {
            zeros[i] += zeros[i-1] + (s[i-1]=='1'?1:0);
        }
        
        int oneFlip = 0;

        minFlips = zeros.back();
        for(int i=s.size()-2; i>=0; i--) {
            oneFlip += (s[i+1] == '0')?1:0;
            minFlips = min(minFlips, zeros[i]+oneFlip);
        }
        return minFlips;
    }
};