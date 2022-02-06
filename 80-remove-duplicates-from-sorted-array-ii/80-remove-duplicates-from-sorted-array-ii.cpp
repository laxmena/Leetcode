class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        if(n < 3) return n;
        for(int i=0; i<n-2; i++) {
            if(nums[i] == nums[i+1] && nums[i+1] == nums[i+2]) {
                nums[i] = INT_MAX; 
                count++;
            } 
        }
        sort(nums.begin(), nums.end());
        return n-count;
    }
};