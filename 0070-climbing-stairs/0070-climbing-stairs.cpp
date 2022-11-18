class Solution {
public:
    map<int, int> m;
    int climbStairs(int n) {
        if(n <= 1) return 1;
        if(m.count(n) > 0) return m[n];
        m[n] = climbStairs(n-1) + climbStairs(n-2);
        return m[n];
    }
};