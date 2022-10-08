class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = INT_MAX;
        int sz = nums.size();
        sort(begin(nums), end(nums));
        for (int i = 0; i < sz && diff != 0; ++i) {
            for (int j = i + 1; j < sz - 1; ++j) {
                int complement = target - nums[i] - nums[j];
                auto it = upper_bound(begin(nums) + j + 1, end(nums), complement);
                int hi = it - begin(nums), lo = hi - 1;
                if (hi < sz && abs(complement - nums[hi]) < abs(diff)) {
                    diff = complement - nums[hi];
                }
                if (lo > j && abs(complement - nums[lo]) < abs(diff)) {
                    diff = complement - nums[lo];
                }
            }
        }
        return target - diff;
    }
};