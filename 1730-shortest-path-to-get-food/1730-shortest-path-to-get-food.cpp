class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        int nr = grid.size();
        int nc = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        int step = 0;
        int index = 1;
        pair<int, int> startPos = findStart(grid, nr, nc);
        
        q.push(startPos);

        while(not q.empty()) {
            while(index--) {
                int currRow = q.front().first;
                int currCol = q.front().second; q.pop();
                for(auto dir : dirs) {
                    int newRow = currRow + dir[0];
                    int newCol = currCol + dir[1];
                    if(newRow < 0 || newRow >= nr || newCol < 0 || newCol >= nc || grid[newRow][newCol] == 'V') {
                        continue;
                    } else if(grid[newRow][newCol] == '#'){
                        return step + 1;
                    } else if(grid[newRow][newCol] == 'O') {
                        grid[newRow][newCol] = 'V';
                        q.push(make_pair(newRow, newCol));
                    }
                }
            }
            index = q.size();
            step += 1;
        }
        return -1;
    }
private:
    pair<int, int> findStart(vector<vector<char>>& grid, int& nr, int& nc) {
        for(int r = 0; r < nr; ++r) {
            for(int c = 0; c < nc; ++c) {
                if(grid[r][c] == '*') {
                    return make_pair(r, c);
                }
            }
        }
        return {-1, -1};
    }
};