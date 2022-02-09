class Solution {
public:
    bool isHappy(int n) {
        set<int> mem;
        while(n && mem.find(n) == mem.end()) {
            mem.insert(n);
            int sum = 0;
            while(n) {
                sum += (n%10)*(n%10);
                n /= 10;
            }
            n = sum;
            if(n == 1) return true;
        }
        return false;
    }
};