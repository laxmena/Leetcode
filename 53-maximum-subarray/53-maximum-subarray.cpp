class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum=nums[0], sum=nums[0];
        for(int i=1; i<nums.size(); i++) {
            int n = nums[i];
            sum = max(sum + n, n);
            maxsum = max(maxsum, sum);
        }
        return maxsum;
    }
};