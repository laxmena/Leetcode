class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minVal = prices[0];
        int profit = 0;
        for(int i=0; i < prices.size(); i++) {
            profit = max(profit, prices[i]-minVal);
            minVal = min(minVal, prices[i]);
        }
        return profit;
    }
};