class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> rob(nums.size(), 0);
        
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        
        rob[0] = nums[0];
        rob[1] = nums[1];
        rob[2] = nums[0] + nums[2];
        
        for(int i=3; i<nums.size(); i++) {
            rob[i] = nums[i] + max(rob[i-2], rob[i-3]);
        }
        
        int n = nums.size();
        return max(rob[n-1], rob[n-2]);
    }
};