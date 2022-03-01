class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1);
        if(n == 0) return vector<int>(1);
        
        for (int i=1; i<=n; i++) {
            result[i] = result[i >> 1] + (i & 1);
        }
        return result;
    }
};

