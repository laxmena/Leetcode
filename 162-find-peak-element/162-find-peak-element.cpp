class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0, r=nums.size()-1, m;
        if(nums.size() == 1) return 0;
        if(nums.size() == 2) return nums[0]>nums[1]?0:1;

        while(l<=r) {
            m = l + (r-l)/2;
            if(m == 0) return nums[m] > nums[m+1]? m: m+1;
            if(m == nums.size()-1) return nums[m]>nums[m-1]? m: m-1;
            if(nums[m] > nums[m-1] && nums[m] > nums[m+1]) return m;
            // See if it is increasing towards right
            if(nums[m] > nums[m-1] && nums[m+1] > nums[m]) {
                l = m+1;
            } else {
                r = m-1;
            }
        }
        return m;
    }
};