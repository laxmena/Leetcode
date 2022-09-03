class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        
        int i=0;
        for(vector<int> row: mat) {
            int sum = 0;
            for(auto elem: row) sum += elem;
            pq.push(make_pair(sum, i));
            i += 1;
        }
        
        vector<int> result;
        while(k--) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};