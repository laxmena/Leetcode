class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int x, y;
        x = mat.size();
        y = mat[0].size();
        if(x*y != r*c) return mat;
        int x1 = -1, y1 = 0;
        int idx = 0;
        vector<vector<int> > result(r, vector<int>(c, 0));
        for(auto row: mat) {
            for(auto col: row) {
                if(idx++ % c == 0) {
                    y1 = 0; x1++;
                }
                result[x1][y1] = col;
                y1++;
            }
        }
        return result;
    }
};