class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        vector<vector<long long>> dp(points.size(), vector<long long>(points[0].size(), -1));
        
        for (int i = 0; i < points[0].size(); ++i) {
            dp[0][i] = points[0][i];
        }
        
        for (int i = 1; i < points.size(); ++i) {
            vector<long long> left_dp(points[i].size(), -1);
            vector<long long> right_dp(points[i].size(), -1);
            
            left_dp[0] = dp[i - 1][0];
            for (int k = 1; k < points[i].size(); ++k) {
                left_dp[k] = max(left_dp[k - 1], dp[i - 1][k] + k);
            }
            
            right_dp.back() = dp[i - 1].back() - points[i].size() + 1;
            for (int k = points[i].size() - 2; k >= 0; --k) {
                right_dp[k] = max(right_dp[k + 1], dp[i - 1][k] - k);
            }
            
            for (int j = 0; j < points[i].size(); ++j) {
                dp[i][j] = max(left_dp[j] - j, right_dp[j] + j) + points[i][j];
            }
        }
        
        long long max_ans = -1;
        for (const auto v : dp.back()) {
            max_ans = max(max_ans, v);
        }
        
        return max_ans;
    }
};