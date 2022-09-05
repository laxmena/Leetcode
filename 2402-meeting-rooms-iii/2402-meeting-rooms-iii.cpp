typedef pair<long, long> pi;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // Create min heap for available rooms and meetings in progress
        priority_queue<int, vector<int>, greater<int>> avl;
        priority_queue<pi, vector<pi>, greater<pi>> prog;
        
        // create avl
        for(int i=0; i<n; i++) avl.push(i);
        
        // create array to store the number of times a room is used
        vector<int> used(n, 0);
        
        // sort meetings based on start time, making use of the default cpp sort
        sort(begin(meetings), end(meetings));
        
        // Iterate through each meetings
        for(vector<int> meet: meetings) {
            int start = meet[0], end = meet[1];
            
            // maked finished meeting rooms available
            while(!prog.empty() && prog.top().first <= start) {
                avl.push(prog.top().second);
                prog.pop();
            }
            
            // If rooms are available, use that
            if(!avl.empty()) {
                int room = avl.top();
                avl.pop();
                used[room]++;
                prog.push(make_pair(end, room));
            } else {
                pi avlRoom = prog.top();
                prog.pop();
                
                long endTime = (end-start) + avlRoom.first;
                prog.push(make_pair(endTime, avlRoom.second));
                used[avlRoom.second]++;
            }
        }
        
        // result: maximum number of time a room is used
        int result = INT_MIN, room = -1;
        for(int i=0; i<n; i++) {
            if(used[i] > result) {
                result = used[i];
                room = i;
            }
        }
        return room;
    }
};