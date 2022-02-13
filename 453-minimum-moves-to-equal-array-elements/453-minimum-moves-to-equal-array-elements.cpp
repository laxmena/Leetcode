class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minval = INT_MAX;
        for(int n: nums) minval = min(minval, n);
        int result = 0;
        for(int n: nums) result += (n - minval);
        return result;
    }
};