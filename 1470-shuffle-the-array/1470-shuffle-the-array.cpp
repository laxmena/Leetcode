class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res;
        int len = nums.size();
        for(int i=0; i<n; i++) {
            for(int j=i; j<len; j+=n) {
                res.push_back(nums[j]);
            }
        }
        return res;
    }
};