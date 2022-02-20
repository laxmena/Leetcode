class Solution {
public:
    bool isLonely(vector<vector<char>>& picture, int row, int col) {
        int bCount = 0;
        for(int i=0; i<picture[0].size(); i++) {
            if(picture[row][i] == 'B') bCount++;
        }
        if(bCount > 1) return false;
        bCount = 0;
        for(int i=0; i<picture.size(); i++) {
            if(picture[i][col] == 'B') bCount++;
        }
        return bCount == 1;
    }
    int findLonelyPixel(vector<vector<char>>& picture) {
        int result = 0;
        int rows = picture.size();
        int cols = picture[0].size();
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(picture[i][j] == 'B') result += isLonely(picture, i, j);
            }
        }
        return result;
    }
};