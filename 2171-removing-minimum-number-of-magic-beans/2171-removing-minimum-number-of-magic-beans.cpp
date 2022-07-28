class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(begin(beans), end(beans));
        long long ls = 0, rs = 0;
        long long ans = LLONG_MAX;
        for(auto elem: beans) rs += elem;

        long long n = beans.size();
        
        for(int i=0; i<n; i++) {
            int elem = beans[i];
            rs -= elem;
            long long remove = ls + rs - (n-1-i)*elem;
            if(remove < ans) ans = remove;
            ls += elem;
        }
        
        return ans;
    }
};