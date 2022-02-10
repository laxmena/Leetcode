class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int minVal = INT_MAX;
        int sum = 0;
        for(int n: nums) {
            sum += n;
            minVal = min(sum, minVal);
        }
        if(minVal > 0) return 1;
        return abs(minVal) + 1;
    }
};