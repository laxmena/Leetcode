class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        // Sort the nums vector
        sort(nums.begin(), nums.end());

        // Find all possible unique combinations in nums 
        // such that nums[i] + nums[j] + nums[k] = 0        
        for(int i=0; i<n; i++) {
            // The array is sorted, and the nums[i] should be 
            // either negative or zero only to achieve zero sum.
            if(nums[i] > 0)
                continue;
            if(i > 0 && nums[i] == nums[i-1]) continue;
            
            int j = i+1;
            int k = n-1;
            int prev;

            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0) {
                    vector<int> entry;
                    entry.push_back(nums[i]);
                    entry.push_back(nums[j]);
                    entry.push_back(nums[k]);
                    result.push_back(entry);

                    int x = nums[j], y = nums[k];
                    if(x == y) break;
                    while(nums[j] == x) j++;
                    while(nums[k] == y) k--;
                }
                else if(sum > 0) k--;
                else if(sum < 0) j++;
            }
        }
        return result;
    }
};