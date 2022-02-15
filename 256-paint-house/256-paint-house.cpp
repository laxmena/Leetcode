class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        vector<int> dp = costs[0];
        
        for(int i=1; i<costs.size(); i++) {
            vector<int> cost = costs[i];
            cost[0] += min(dp[1], dp[2]);
            cost[1] += min(dp[0], dp[2]);
            cost[2] += min(dp[0], dp[1]);
            dp = cost;
        }

        return min(dp[0], min(dp[1], dp[2]));
    }
};
 

