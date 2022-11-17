class Solution {
public:
    bool canJump(vector<int>& nums) {
        int steps = nums[0], n = nums.size();
        for(int i=1; i<n; i++) {
            if(steps == 0) return false;
            steps -= 1;
            steps = max(steps, nums[i]);
        }
        return true;
    }
};