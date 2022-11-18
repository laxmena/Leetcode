class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        
        sort(begin(intervals), end(intervals));
        
        for(auto interval: intervals) {
            if(result.empty()) {
                result.push_back(interval);
                continue;
            }
            vector<int> back = result.back();
            if(back[1] >= interval[0]) {
                result.pop_back();
                result.push_back({min(back[0],interval[0]), max(back[1], interval[1])});
            } else {
                result.push_back(interval);
            }
        }
        
        return result;
    }
};