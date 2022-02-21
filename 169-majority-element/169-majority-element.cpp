class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0, num1;
        for(int n: nums) {
            if(count == 0) num1 = n;
            if(n == num1) count++;
            else count--;
        }
        return num1;
    }
};