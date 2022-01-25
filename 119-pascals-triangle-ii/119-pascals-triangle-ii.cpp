class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1,1);
        for(int i=0; i<=rowIndex; i++) {
            int prev = 1;
            for(int j=1; j<i; j++) {
                res[j] = res[j] + prev;
                prev = res[j] - prev;
            }
        }
        return res;
    }
    
};