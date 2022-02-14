class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n1s = nums1.size(), n2s = nums2.size();
        if(n1s > n2s*6 || n2s > n1s*6) return -1;
        int sum1=0, sum2=0;
        for(int n: nums1) sum1 += n;
        for(int n: nums2) sum2 += n;
        if(sum1 > sum2) {
            swap(nums1, nums2);
            swap(sum1, sum2);
        }
        int diff = abs(sum1 - sum2);
        if(diff == 0) return 0;
        
        vector<int> arr;
        for(int &n: nums1) arr.push_back(6-n);
        for(int &n: nums2) arr.push_back(n-1);
        sort(rbegin(arr), rend(arr));
        int counter = 0;
        for(int &n: arr) {
            counter++;
            diff -= n;
            if(diff <= 0) return counter;
        }
        
        return -1;
    }
};