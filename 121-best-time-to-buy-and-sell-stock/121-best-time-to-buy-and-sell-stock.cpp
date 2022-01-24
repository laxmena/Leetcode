class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mval = prices[0];
        int profit = 0;
        for(auto n: prices) {
            profit = max(profit, n-mval);
            mval = min(mval, n);
        }
        return profit;
    }
};