class Solution {
public:
    
    int numRookCaptures(vector<vector<char>>& board) {
        int count = 0;
        int rr, rc;
        for(int i=0; i<8; i++) for(int j=0; j<8; j++)
            if(board[i][j] == 'R') {
                rr = i; rc = j;
            }
        // check col top
        for(int i=rr-1; i>=0; i--) {
            if(board[i][rc] == 'p') { count++; break; } 
            else if(board[i][rc] == 'B') break;
        }
        
        // check bottom
        for(int i=rr+1; i<8; i++) {
            if(board[i][rc] == 'p') { count++; break; }
            else if(board[i][rc] == 'B') break;
        }

        // check col top
        for(int i=rc-1; i>=0; i--) {
            if(board[rr][i] == 'p') { count++; break; } 
            else if(board[rr][i] == 'B') break;
        }
        
        // check bottom
        for(int i=rc+1; i<8; i++) {
            if(board[rr][i] == 'p') { count++; break; }
            else if(board[rr][i] == 'B') break;
        }        
        
        return count;
    }
};