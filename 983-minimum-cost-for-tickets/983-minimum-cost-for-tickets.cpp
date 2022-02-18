class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(365+1, 0);
        sort(begin(days), end(days));
        for(int i=1, j=0; i<366 && j<days.size(); i++) {
            if(i == days[j]) {
                int day7 = (i>7? dp[i-7]: 0) + costs[1];
                int day30 = (i>30? dp[i-30]: 0) + costs[2];
                int day1 = dp[i-1] + costs[0];
                dp[i] = min(min(day1, day30), day7);
                j++;
            } else {
                dp[i] = dp[i-1];
            }
        }
        return dp[days.back()];
    }
};