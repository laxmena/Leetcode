class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> dp[nums.size()];
        int idx=0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j <= i; j++){
                if(nums[i]%nums[j] == 0) {
                    if(dp[i].size() <= dp[j].size())
                    {
                        dp[i] = dp[j];
                    }
                }
            }
            dp[i].push_back(nums[i]);
            if(dp[i].size() >= dp[idx].size()) idx = i;
        }     
        return dp[idx];
    }
};