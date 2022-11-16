class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for(int i=1; i<=nums.size(); i++) {
            res = res ^ i;
            res = res ^ nums[i-1];
        }
        return res;
    }
};