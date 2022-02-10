class Solution {
public:
    vector<int> prefix;
    Solution(vector<int>& w) {
        for(int n: w)
            prefix.push_back(n + (prefix.empty()? 0: prefix.back()));
    }
    
    int pickIndex() {
        float ridx = (float) rand() / RAND_MAX;
        float target = ridx * prefix.back();
        return upper_bound(begin(prefix), end(prefix), target) - begin(prefix);
    }
    
    
};
