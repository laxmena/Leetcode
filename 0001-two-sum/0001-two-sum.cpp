class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        
        for(int i=0; i<nums.size(); i++) {
            int n = nums[i];
            if(m.find(n) != m.end()) {
                return {i, m[n]};
            }
            m[target-n] = i;
        }
        return {};
    }
};