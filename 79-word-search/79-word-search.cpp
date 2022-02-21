class Solution {
public:
    bool search(vector<vector<char>>& board, string word, int x=0, int y=0) {
        // Exit conditions
        if(word.size() < 1 || board[x][y] == '0') return false;
        if(board[x][y] != word[0]) return false;
        if(word.size() == 1) return true;
        
        char ch = board[x][y]; 
        board[x][y] = '0'; // mark as visited

        bool up  = false, down = false, right = false, left = false;
        string sub = word.substr(1);
        // search up
        if(x > 0) {
            up = search(board, sub, x-1, y);
        }        
        // search down
        if(x < board.size()-1) {
            down = search(board, sub, x+1, y);
        }        
        // search right
        if(y < board[0].size()-1) {
            right = search(board, sub, x, y+1);
        }
        // search left
        if(y > 0) {
            left = search(board, sub, x, y-1);
        }
        
        board[x][y] = ch; // unmark the visited block
        return up | down | left | right;
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool result = false;
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                result = search(board, word, i, j);
                if(result) return true;
            }
        }
        return false;
    }
};