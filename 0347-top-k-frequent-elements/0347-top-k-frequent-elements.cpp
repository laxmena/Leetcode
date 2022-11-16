class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        for(int n: nums) m[n]++;
        priority_queue<vector<int>> pq;
        for(auto const& val: m) pq.push({val.second, val.first});
        vector<int> res;
        while(k--) {
            res.push_back(pq.top()[1]);
            pq.pop();
        }
        return res;
    }
};