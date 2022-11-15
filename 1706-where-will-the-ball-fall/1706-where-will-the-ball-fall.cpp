class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> result;
        for(int s=0; s<n; s++) {
            
            int x = 0, y = s;
            // The each ball, trace its route through the rows
            // cout << "start x: " << x << " y: " << y << "\n";            
            while(x != m && y!= -1) {
                // the ball is locked
                if((grid[x][y] == 1 && y == n-1) || 
                   (grid[x][y] == -1 && y == 0) ||
                   (grid[x][y] == 1 && grid[x][y+1] == -1) || 
                   (grid[x][y] == -1 && grid[x][y-1] == 1)) {

                    y = -1;
                    break;
                }

                if(grid[x][y] == 1 && grid[x][y+1] == 1) y++;
                if(grid[x][y] == -1 && grid[x][y-1] == -1) y--;
                
                // cout << "x: " << x << " y: " << y << endl;
                
                x++;
            }
            result.push_back(y);            
        }
        
        return result;
    }
};