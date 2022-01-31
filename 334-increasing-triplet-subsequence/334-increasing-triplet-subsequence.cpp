class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3) return false;
        int fn=INT_MAX, sn=INT_MAX;
        for(int n: nums) {
            if(n <= fn) fn = n;
            else if(n <= sn) sn = n;
            else return true;
        }
        return false;
    }
};