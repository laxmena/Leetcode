class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix.size();
        int n = matrix[0].size();
        int move[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; //Right, Down, Left, Up
        // Down -> decrease, up->decrease
        int dir = 0; 
        int z = n, x = 0, y = -1;
        while(z) {
            for(int i=0; i<z; i++) {
                x += move[dir][0];
                y += move[dir][1];
                result.push_back(matrix[x][y]);
            }
            dir = (dir+1) % 4;
            if(dir%2) { m-=1; z=m;  }
            else { n-=1; z=n; }
        }
        return result;
    }
};