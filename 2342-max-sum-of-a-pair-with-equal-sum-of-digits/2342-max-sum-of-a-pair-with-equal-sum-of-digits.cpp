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
        map<int, pair<int, int>> m;
        for(auto num: nums) {
            int sum = digitSum(num);
            cout << "Sum: " << sum << "\n";
            if(m.find(sum) == m.end()) {
                m[sum] = make_pair(INT_MIN, num); //max2, max1            
            } else if(num >= m[sum].second) {
                m[sum].first = m[sum].second;
                m[sum].second = num;
            } else if(num >= m[sum].first) {
                m[sum].first = num;
            }    
        }
        int maxSum = -1;
        for(auto kp: m) {
            maxSum = max(maxSum, kp.second.second + kp.second.first);
        }
        return maxSum;
    }
};