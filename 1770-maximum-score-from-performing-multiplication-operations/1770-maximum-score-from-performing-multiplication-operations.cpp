class Solution {
public:
    int maximumScore(vector<int>& v, vector<int>& m) {
        
        vector<vector<int>> dp(m.size()+1, vector<int>(m.size()+1));
        for(int i = 0; i < dp.size(); i++){
            dp[i][dp[0].size()-1] = 0;
            dp.back()[i] = 0;
        }
        for(int i = dp.size()-2; i >= 0; i--) {
            for(int j = dp[0].size()-2; j >=0; j--) {
                dp[i][j] = max(m[i]*v[j] + dp[i+1][j+1],
                                    m[i]*v[v.size()-1-(abs(i-j))] + dp[i+1][j]);
            }
        }
        return dp[0][0];
    }
};