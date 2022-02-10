class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxOnes = 0;
        int ones = 0;
        for(int n: nums) {
            ones = (ones*n) + n;
            maxOnes = max(maxOnes, ones);
        }
        return maxOnes;
    }
};