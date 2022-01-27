class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> mem(nums.size());
        for(int i=0; i<nums.size(); i++) {
            if(i < 2) { mem[i] = nums[i]; continue; }
            if(i == 2) { mem[i] = nums[i] + mem[0]; continue; }
            mem[i] = nums[i] + max(mem[i-2], mem[i-3]);
        }
        int n = nums.size();
        if(n < 2) return mem[0];
        return max(mem[n-1], mem[n-2]);
    }
};