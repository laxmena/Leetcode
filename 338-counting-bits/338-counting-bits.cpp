class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bits(n+1, 0);
        for(int i=0; i<=n; i++) {
            int num = i;
            int b = 0;
            while(num) { b+=(num&1); num >>= 1;}
            bits[i] = b;
        }
        return bits;
    }
};