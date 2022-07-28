typedef pair<int, int> pi;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<deque<int>> vq;
        for(auto num: nums) vq.push_back(deque<int>(begin(num), end(num)));
        
        int minDif = INT_MAX;
        vector<int> resRange(2, 0);
        
        priority_queue<pi, vector<pi>, greater<pi> > minQ;
        pi maxp = make_pair(INT_MIN, -1);
        
        for(int i=0; i<vq.size(); i++) {
            deque<int> q = vq[i];
            minQ.push(make_pair(q.front(), i));
            if(q.front() > maxp.first) {
                maxp.first = q.front();
                maxp.second = i;
            }
        }
        
        while(true) {
            pi minp = minQ.top();
            minQ.pop();
            
            int range = maxp.first - minp.first;
            if(range < minDif) {
                minDif = range;
                resRange[0] = minp.first;
                resRange[1] = maxp.first;
            }
            
            vq[minp.second].pop_front();            
            if(vq[minp.second].size() == 0) break;
            
            minQ.push(make_pair(vq[minp.second][0], minp.second));
            if(vq[minp.second][0] > maxp.first) {
                maxp.first = vq[minp.second][0];
                maxp.second = minp.second;
            }
        }
        
        return resRange;
    }
};