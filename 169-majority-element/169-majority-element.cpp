class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int i=0, m;
        for(auto n: nums) {
            if(i == 0) m = n;
            if(m == n) i++;
            else i--;
        }
        return m;
    }
};