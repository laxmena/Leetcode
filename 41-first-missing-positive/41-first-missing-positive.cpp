class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // Check for nums if it has 1
        bool hasOne = false;
        for(auto n: nums) hasOne = hasOne | (n == 1);
        if(!hasOne) return 1;
        
        int n = nums.size();
        
        // Remove negative numbers, zeros and numbers greater than n
        for(int i=0; i<n; i++) {
            if(nums[i] <= 0 || nums[i]>n) nums[i] = 1; 
        }
        
        // Take each value in array, make element in that index as negative
        for(int i=0; i<n; i++) {
            if(nums[abs(nums[i])-1] > 0) nums[abs(nums[i])-1] *= -1;
        }
        
        // Iterate through array and find the index where the number is positive
        for(int i=0; i<n; i++) {
            if(nums[i] > 0) return i+1;
        }
        
        return n+1;
    }
};