class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        map<int, int> hist;
        hist[0] = -1;
        long long sum = 0;
        int maxLen = 0;
        for(int i=0; i<nums.size(); i++) {            
            sum += nums[i];           
            if(hist.find(sum-k) != hist.end()) {
                maxLen = max(maxLen, (i - hist[sum-k]));
            }
            if(hist.find(sum) == hist.end()) hist[sum] = i;
        }
        return maxLen;
    }
};