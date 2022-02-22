class Solution {
public:
    int titleToNumber(string columnTitle) {
        int row = 0, n=columnTitle.size();
        for(int i=0; i<n; i++) {
            row += pow(26, i)*(columnTitle[n-i-1]-'A'+1);
        }
        return row;
    }
};