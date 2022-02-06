class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i, j=1, n=nums.size();
        if(n < 2) return n;
        for(i=1; i<n; i++) {
            if(nums[i] == nums[i-1]) continue;
            nums[j++] = nums[i];
        }
        return j;
    }
};