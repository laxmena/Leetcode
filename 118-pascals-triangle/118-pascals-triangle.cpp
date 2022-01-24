class Solution {
public:
    vector<vector<int>> generate(int r) {
        vector<vector<int> > pascal;
        for(int i=1; i<=r; i++) {
            pascal.push_back(vector<int>(i, 1));
            for(int j=1; j<=i; j++) {
                if(j == 1 || j == i) continue;
                pascal[i-1][j-1] = pascal[i-2][j-1] + pascal[i-2][j-2];
            }
        }
        return pascal;
    }
};