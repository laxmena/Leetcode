class Solution {
public:
    long long numberOfWays(string s) {
        vector<int> before(s.size(), 0), after(s.size(), 0);
        vector<int> track(2, 0), retrack(2, 0);
        
        // Populate before
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '0') {
                track[0] += 1;
                before[i] = track[1];
            } else {
                track[1] += 1;
                before[i] = track[0];
            }
            // populate after
            int ri = s.size() -1 -i;
            if(s[ri] == '0') {
                retrack[0] += 1;
                after[ri] = retrack[1];
            } else {
                retrack[1] += 1;
                after[ri] = retrack[0];
            }
        }
        
        long long result = 0;
        for(int i=0; i<before.size(); i++) {
            result += before[i]*after[i];
        }
        
        return result;
    }
};