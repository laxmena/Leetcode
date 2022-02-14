typedef pair<int, int> pi;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> results;
        map<int, int> freq;
        for(int n: nums) freq[n]++;

        auto cmp = [](const pi &a, const pi &b) {
            return a.second < b.second;
        };
        priority_queue<pi, vector<pi>, decltype(cmp)> pq(freq.begin(), freq.end(), cmp);
        
        while(k--) {
            results.push_back(pq.top().first);
            pq.pop();
        }
        return results;
    }
};