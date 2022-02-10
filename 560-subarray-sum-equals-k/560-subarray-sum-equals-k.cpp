class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> map;
        int count = 0, sum = 0;
        map[0] = 1;
        for(int n: nums) {
            sum += n;
            if(map.find(sum - k) != map.end()) 
                count+=map[sum-k];
            map[sum]++;
        }
        return count;
    }
};