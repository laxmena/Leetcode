class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        // Two Step Rotation
        // Step 1: Rotate on Axis
        for(int i=0; i<m.size(); i++) for(int j=0; j<=i; j++) swap(m[i][j], m[j][i]);

        // Flip
        int half = m.size() / 2;
        for(int i=0; i<m.size(); i++) {
            for(int j=0; j<half; j++) {
                swap(m[i][j], m[i][m.size()-j-1]);
            }
        }
    }
};