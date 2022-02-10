class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int minVal = nums[0], n=nums.size();
        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += nums[i];
            minVal = min(sum, minVal);
        }
        if(minVal > 0) return 1;
        return abs(minVal) + 1;
    }
};