class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++) {
            set<int> rows, cols;
            int row, col;
            for(int j=0; j<9; j++) {
                if(board[i][j] != '.') {
                    row = board[i][j] - '0';
                    if(rows.find(row) != rows.end()) {
                        return false;
                    }                    
                    rows.insert(row);
                }
                if(board[j][i] != '.') {
                    col = board[j][i] - '0';
                    if(cols.find(col) != cols.end()) {
                        return false;
                    }
                    cols.insert(col);
                }
            }
        }
        
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                set<int> sq;
                int row=i*3, col=j*3;

                for(int k=0; k<3; k++) {
                    int v1=board[row+k][col+0] - '0';
                    int v2=board[row+k][col+1] - '0';
                    int v3=board[row+k][col+2] - '0';

                    if( sq.find(v1) != sq.end() ||
                        sq.find(v2) != sq.end() ||
                        sq.find(v3) != sq.end()) {
                            
                            return false;
                        }
                    
                    if(v1 != -2) sq.insert(v1);
                    if(v2 != -2) sq.insert(v2);
                    if(v3 != -2) sq.insert(v3);                        
                }
            }
        }
        return true;
    }
};