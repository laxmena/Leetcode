class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mem;
        vector<int> result;
        for(int i=0; i<nums.size(); i++) {
            int n = nums[i];
            if(mem.find(target - n) != mem.end()) {
                result.push_back(mem[target - n]);
                result.push_back(i);
                return result;
            }
            mem[n] = i;
        }
        return result;
    }
};