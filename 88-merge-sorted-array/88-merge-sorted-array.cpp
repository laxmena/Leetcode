class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int end = nums1.size() - 1;
        int ptr1 = m-1, ptr2 = n-1;
        for(int p = m + n - 1; p >= 0; p--) {
            if(ptr2 < 0) break;
            if(ptr1 >= 0 && nums1[ptr1] > nums2[ptr2]) {
                nums1[p] = nums1[ptr1--];
            } else {
                nums1[p] = nums2[ptr2--];
            }
        }
    }
};