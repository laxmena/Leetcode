class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while(n) {
            sum += n%10;
            n /= 10;            
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        sort(begin(nums), end(nums));
        
        map<int, vector<int>> m;
        for(auto num: nums) {
            m[digitSum(num)].push_back(num);
        }
        int maxSum = -1;
        for(auto kp: m) {
            int n = kp.second.size();
            if(n>1) {
                maxSum = max(maxSum, kp.second[n-1] + kp.second[n-2]);
            }
        }
        return maxSum;
    }
};