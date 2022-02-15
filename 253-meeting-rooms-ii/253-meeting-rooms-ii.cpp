class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        priority_queue<int, vector<int>, greater<int>> minheap;
        sort(intervals.begin(), intervals.end());
        for(vector<int> v: intervals) {
            if(!minheap.empty() && minheap.top() <= v[0]) {
                minheap.pop();
            }
            minheap.push(v[1]);
        }
        return minheap.size();
    }
};