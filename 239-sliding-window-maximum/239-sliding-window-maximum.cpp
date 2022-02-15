class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> left = vector<int>(nums.size());
        vector<int> right = vector<int>(nums.size());
        
        if(nums.size()*k == 0) return vector<int>();
        int blockmax = nums[0];
        int rblockmax = nums[nums.size()-1];
        for(int i=0; i<nums.size(); i++) {
            int j = nums.size()-i-1;
            if(i%k == 0) { blockmax = nums[i]; }
            blockmax = max(nums[i], blockmax);
            left[i] = blockmax;
            if((j+1)%k == 0) { rblockmax = nums[j]; }
            rblockmax = max(nums[j], rblockmax);
            right[j] = rblockmax;
        }
        
        vector<int> result(left.size()-k+1);
        for(int i=0; i<left.size()-k+1; i++) {
            result[i] = max(left[i+k-1], right[i]);
        }
        return result;
    }
};