class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0, leftSum=0;
        for(int n: nums) totalSum += n;
        for(int i=0; i<nums.size(); i++) {
            totalSum -= nums[i];
            leftSum = leftSum + (i>0 ? nums[i-1]: 0);
            if(totalSum == leftSum) return i;
        }
        return -1;
    }
};