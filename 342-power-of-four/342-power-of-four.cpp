class Solution {
public:
    bool isPowerOfFour(int n) {
        for(int i=0; i<32; i+=2) {
            if(1<<i == n) return true;
        }
        return false;
    }
};