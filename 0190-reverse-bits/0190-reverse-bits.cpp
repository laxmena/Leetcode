class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        int x = 32;

        for(int i=0; i<32; i++) {
            int shift = x-i-1;
            int bit = (n&(1<<i)) >> i;
            res = res << 1;
            res = res | bit;
        }
    
        return res;
    }
};

// x = 6
// n = 111000
// r = 0
    
// r << 1 => 00
// r | 