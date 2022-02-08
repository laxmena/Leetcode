class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> result(n+1, 0);
        for(vector<int> book: bookings) {
            result[book[0]-1] += book[2];
            result[book[1]] -= book[2];
        }
        for(int i=1; i<n; i++) {
            result[i] += result[i-1];
        }
        result.erase(result.begin()+n);
        return result;
    }
};