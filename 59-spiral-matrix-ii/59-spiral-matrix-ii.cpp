class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // Right,  Down, Left, Up
        vector<vector<int> > result(n, vector<int>(n, 0));
        int dir = 0;
        int x=0, y=-1;
        int counter = 0;
        
        while(n) {
            for(int i=0; i<n; i++) {
                x += moves[dir][0];
                y += moves[dir][1];
                result[x][y] = ++counter;
            }
            dir = (dir+1)%4;
            if(dir%2) n--;
        }
        
        return result;
    }
};