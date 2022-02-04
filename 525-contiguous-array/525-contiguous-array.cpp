class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int val = 0, len = 0;
        map<int, int> mem;
        mem[0] = -1;
        for(int i=0; i<nums.size(); i++) {
            val += (nums[i] == 0)? 1: -1;
            if(mem.find(val) != mem.end()) {
                len = max(len, i-mem[val]);
            } else {
                mem[val] = i;
            }
        }
        return len;
    }
};