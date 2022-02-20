class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        queue<int> flips;
        int count = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] != (flips.size()%2 ? 0 : 1)) {
                flips.push(i+k-1);
                ++count;
            }
            if(!flips.empty() && flips.front() <= i) flips.pop();
        }
        return flips.empty()? count:-1;
    }
};