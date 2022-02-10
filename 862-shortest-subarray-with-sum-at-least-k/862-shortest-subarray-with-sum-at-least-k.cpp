class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<pair<int, int>> dq = {{-1, 0}}; 
        long prefix = 0;
        int ans = INT_MAX; 
        for (int i = 0; i < nums.size(); ++i) {
            prefix += nums[i]; 
            while (dq.size() && prefix - dq.front().second >= k) {
                ans = min(ans, i - dq.front().first); 
                dq.pop_front(); 
            }
            while (dq.size() && dq.back().second >= prefix) dq.pop_back(); 
            dq.emplace_back(i, prefix); 
        }
        return ans < INT_MAX ? ans : -1;
    }
        
};