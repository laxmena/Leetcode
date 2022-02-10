class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftProduct(n);

        leftProduct[0] = 1;
        // Compute Left Product
        for(int i=1; i<n; i++)
            leftProduct[i] = leftProduct[i-1] * nums[i-1];
        
        // Right Product
        int rightProduct = 1;
        leftProduct[n-1] *= rightProduct;
        for(int i=n-2; i>=0; i--) {
            rightProduct *= nums[i+1];
            leftProduct[i] *= rightProduct;
        }
        
        return leftProduct;
    }
};