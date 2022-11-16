class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> m(prices.size(), INT_MAX);

        for(int i=0; i<prices.size(); i++) {
            if(i == 0) m[i] = prices[i];
            else {
                m[i] = min(m[i-1], prices[i]);
            }
        }

        int profit = 0;
        for(int i=prices.size()-1; i >= 0; i--) {
            profit = max(profit, prices[i]-m[i]);
        }
        return profit;
    }
};