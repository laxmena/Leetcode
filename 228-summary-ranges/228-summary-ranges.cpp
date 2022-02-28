class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if(nums.size() == 0) return result;
        int start=nums[0];
        for(int i=1; i<nums.size()+1; i++) {
            if(i == nums.size() || nums[i]-1 != nums[i-1]) {
                if(start == nums[i-1]) result.push_back(to_string(nums[i-1]));
                else result.push_back(to_string(start) + "->" + to_string(nums[i-1]));
                if(i < nums.size()) start = nums[i];
            }
        }
        return result;
    }
};