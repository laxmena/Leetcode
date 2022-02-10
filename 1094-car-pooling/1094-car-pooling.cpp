class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int loc[1001] = {0};
        int people, start, end;
        int n = trips.size();
        int locMax = trips[0][2];

        for(int i=0; i<n; i++) {
            people = trips[i][0];
            if(people > capacity) return false;
            start = trips[i][1], end = trips[i][2];
            loc[start] += people;
            loc[end] -= people;
            locMax = max(locMax, end);
        }
        
        int sum = 0;
        for(int i=0; i<locMax+1; i++) {
            sum += loc[i];
            loc[i] = sum;
            if(loc[i] > capacity) return false;
        }
        return true;
    }
};