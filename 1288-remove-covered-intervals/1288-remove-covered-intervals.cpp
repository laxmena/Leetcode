class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals));
        vector<vector<int>> st;
        int covered = 0;
        st.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++) {
            // cout << st.back()[0] << " " << st.back()[1] << " | " << intervals[i][0] << " " << intervals[i][1] << "\n";
            if(st.back()[0] <= intervals[i][0] && st.back()[1]>=intervals[i][1]) {
                covered++;
                continue;
            } else if(st.back()[0] == intervals[i][0]) {
                st.back()[1] = max(st.back()[1], intervals[i][1]);
                continue;
            }
            st.push_back(intervals[i]);
        }
        return st.size();
    }
};