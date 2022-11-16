class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int zeroCount = 0;
        
        for(int n: nums) {
            if(n == 0) zeroCount++;
            else product *= n;
        }        
        
        vector<int> result(nums.size(), 0);
        if(zeroCount > 1) return result;
        
        for(int i=0; i<nums.size(); i++) {
            if(zeroCount == 1) {
                if(nums[i] == 0) result[i] = product;
                else result[i] = 0;
            } else {
                result[i] = product / nums[i];
            }
        }
        
        return result;
        
    }
};