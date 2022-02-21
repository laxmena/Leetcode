class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> pq;
        for(auto& n: arr) {
            pq.push(make_pair(abs(n-x), n));
            if(pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> result;
        while(!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        sort(begin(result), end(result));
        return result;
    }
};