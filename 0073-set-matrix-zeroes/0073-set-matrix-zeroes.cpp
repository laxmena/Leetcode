class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> row, col;
        int m = matrix.size(), n = matrix[0].size();
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(matrix[i][j] == 0) {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        
        for(auto r: row) {
            for(int i=0; i<n; i++) matrix[r][i] = 0;
        }
        for(auto c: col) {
            for(int i=0; i<m; i++) matrix[i][c] = 0;
        }
    }
};