class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxOnes = 0;
        int ones = 0;
        for(int n: nums) {
            if(n == 1) {
                ones++;
                maxOnes = max(maxOnes, ones);
            } else {
                ones = 0;
            }
        }
        return maxOnes;
    }
};