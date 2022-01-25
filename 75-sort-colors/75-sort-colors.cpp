class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count[3] = {0};
        for(auto n: nums) count[n]++;
        
        int start = 0;
        for(int c=0; c<3; c++) {
            int n = count[c];
            for(int i=start; i<start+n; i++) nums[i] = c;
            start += n;
        }
    }
};