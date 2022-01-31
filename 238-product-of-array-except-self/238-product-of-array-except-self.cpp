class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size());
        int n = nums.size(), product = 1;
        result[0] = 1;
        for(int i=1; i<n; i++) {
            product *= nums[i-1];
            result[i] = product;
        }
        
        product = 1;
        for(int i=n-2; i>=0; i--) {
            product *= nums[i+1];
            result[i] *= product;
        }
        return result;
    }
};