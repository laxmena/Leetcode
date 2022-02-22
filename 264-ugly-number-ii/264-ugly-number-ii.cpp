class Solution {
public:
    int nthUglyNumber(int n) {
        if(n <= 0) return 0;
        if(n == 1) return 1;
        vector<int> v(n);
        v[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        for(int i=1; i<n; i++) {
            v[i] = min(2*v[p2], min(3*v[p3], 5*v[p5]));
            if(v[i] == 2*v[p2]) p2++;
            if(v[i] == 3*v[p3]) p3++;
            if(v[i] == 5*v[p5]) p5++;
        }
        return v[n-1];
    }
};