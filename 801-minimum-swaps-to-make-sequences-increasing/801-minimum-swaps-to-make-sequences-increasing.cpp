class Solution {
public:

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int count = 0, up = 0, down = 0;
        for(int i=0; i<nums1.size(); i++) {
            if(nums1[i] > nums2[i]) up++;
            else down++;
            
            if(i==nums1.size()-1 || max(nums1[i], nums2[i]) < min(nums1[i+1], nums2[i+1])) {
                count += min(up, down);
                up = down = 0;
            }
        }
        return count;
    }
};