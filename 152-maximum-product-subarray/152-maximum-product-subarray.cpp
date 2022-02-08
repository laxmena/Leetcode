class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() < 2) return nums[0];
        int product = INT_MIN;
        int maxn = 1, minn = 1;
        for(int n: nums) {
            if(maxn == 0) maxn = 1;
            if(minn == 0) minn = 1;
            int tmax = maxn;
            maxn = max(0, max(maxn*n, minn*n));
            minn = min(0, min(minn*n, tmax*n));
            product = max(product, max(maxn, minn));
        }
        return product;
    }
};