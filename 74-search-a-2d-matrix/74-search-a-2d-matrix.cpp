class Solution {
public:
    bool binarySearch(vector<int>& row, int e, int target) {
        int s=0, m;
        while(s <= e) {
            int m = s + (e-s)/2;
            if(row[m] == target) return true;
            if(row[m] > target) e = m - 1;
            else s = m + 1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        for(int i=0; i<rows; i++) {
            if(matrix[i][0] <= target && matrix[i][cols-1] >= target) return binarySearch(matrix[i], cols, target);
        }
        return false;
    }
};