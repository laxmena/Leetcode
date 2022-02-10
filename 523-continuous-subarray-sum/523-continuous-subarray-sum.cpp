class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        set<int> history;
        int sum = nums[0];
        int prev = sum % k;
        for(int i=0; i<nums.size(); i++) {
            sum = (sum + nums[i]) % k;
            if(history.count(sum)) return true;
            history.insert(prev);
            prev = sum;
        }
        return false;
    }
};