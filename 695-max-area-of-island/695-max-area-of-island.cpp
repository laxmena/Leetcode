class Solution {
public:
    
    int findArea(vector<vector<int>>& grid, int row, int col) {
        if(grid[row][col] != 1) return 0;
        
        cout << row << " " << col << "\n";
        grid[row][col] = -1;
        
        int top=0, left=0, right=0, bottom=0;
        
        if(row-1 >= 0) top = findArea(grid, row-1, col);
        if(row+1 < grid.size()) bottom = findArea(grid, row+1, col);
        if(col-1 >= 0) left = findArea(grid, row, col-1);
        if(col+1 < grid[0].size()) right = findArea(grid, row, col+1);        
        
        return 1 + right + bottom + top + left;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        
        for(int row=0; row<grid.size(); row++) {
            for(int col=0; col<grid[0].size(); col++) {
                cout << "-->" << row << " " << col << "\n";
                maxArea = max(findArea(grid, row, col), maxArea);
                cout << "Max Area: " << maxArea << "\n";
            }
        }
        
        return maxArea;
    }
};