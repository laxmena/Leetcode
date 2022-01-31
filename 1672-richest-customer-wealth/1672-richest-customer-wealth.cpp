class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxw = 0;
        for(auto acc: accounts) {
            maxw = max(maxw, accumulate(acc.begin(), acc.end(), 0));
        }
        return maxw;
    }
};