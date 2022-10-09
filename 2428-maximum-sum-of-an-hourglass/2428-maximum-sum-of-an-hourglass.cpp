class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        long long int res = 0;
        for(int i=0; i<grid.size()-2; i++) {
            for(int j=0; j<grid[0].size()-2; j++) {
                long long int sum = grid[i][j] + grid[i][j+1] + grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2];
                res = max(res, sum);
            }
        }
            
        return res;
    }
};