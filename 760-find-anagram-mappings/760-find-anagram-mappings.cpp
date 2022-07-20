class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> idx;
        for(int i=0; i<nums2.size(); i++) idx[nums2[i]] = i;
        for(int i=0; i<nums1.size(); i++) {
            nums1[i] = idx[nums1[i]];
        }
        return nums1;
    }
};