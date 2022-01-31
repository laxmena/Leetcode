class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bits(n+1, 0);
        for(int x=1; x<=n; x++) {
            bits[x] = bits[x>>1] + (x&1);
        }
        return bits;
    }
};