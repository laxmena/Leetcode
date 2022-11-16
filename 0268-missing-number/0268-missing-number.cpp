class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for(int n: nums) res = res ^ n;
        for(int i=0; i<= nums.size(); i++) res = res ^ i;
        return res;
    }
};