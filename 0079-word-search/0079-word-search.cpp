class Solution {
public:

    
    bool searchGrid(vector<vector<char>>& board, int i, int j, deque<char>& word) {
        if(word.empty()) return true;
        if(i < 0 || j < 0) return false;
        if(i >= board.size() || j >= board[0].size()) return false;
        pair<int, int> p({i, j});
        
        if(board[i][j] != word.front()) 
            return false;
        
        char val = word.front();
        
        word.pop_front();
        board[i][j] = '-';
        bool result = searchGrid(board, i+1, j, word) || searchGrid(board, i-1, j, word) || searchGrid(board, i, j+1, word) || searchGrid(board, i, j-1, word);
        
        board[i][j] = val;
        word.push_front(val);
        
        return result;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        deque<char> w(begin(word), end(word));
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(searchGrid(board, i, j, w))
                    return true;
            }
        }
        return false;
    }
};