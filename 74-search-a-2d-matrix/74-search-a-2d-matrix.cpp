class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        for(int i=0; i<rows; i++) {
            if(target >= matrix[i][0] && target <= matrix[i][cols-1]) {
                return binarySearch(&matrix[i], target);
            }
        }
        return false;
    }
    
    bool binarySearch(vector<int> *arr, int target) {
        int l=0, r=(*arr).size();
        int m;
        while(l < r) {
            m = l + (r-l)/2;
            if((*arr)[m] == target) return true;
            if((*arr)[m] > target) r = m;
            else l = m+1;
        }
        return (*arr)[m] == target;
    }
};