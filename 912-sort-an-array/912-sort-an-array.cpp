class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(begin(nums), end(nums));
        return nums;
    }
};