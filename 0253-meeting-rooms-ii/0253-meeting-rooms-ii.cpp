class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int minrooms = 0;
        
        sort(begin(intervals), end(intervals));
        for(auto interval: intervals) {
            if(pq.empty()) {
                pq.push(interval[1]);
                continue;
            }
            
            if(pq.top() <= interval[0]) {
                pq.pop();
            }
            pq.push(interval[1]);
        }
        
        return pq.size();
    }
};