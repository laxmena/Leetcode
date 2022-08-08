class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        set<vector<int>> qpos(begin(queens), end(queens));
        vector<vector<int>> result;
        int x=king[0], y=king[1];
        
        // vertical
        for(int i=x; i>=0; i--) {
            vector<int> pos({i, y});
            if(qpos.find(pos) != qpos.end()) {
                result.push_back(pos);
                break;
            }
        }
        for(int i=x; i<8; i++) {
            vector<int> pos({i, y});
            if(qpos.find(pos) != qpos.end()) {
                result.push_back(pos);
                break;
            }
        }
        // horizontal
        for(int j=y; j>=0; j--) {
            vector<int> pos({x, j});
            if(qpos.find(pos) != qpos.end()) {
                result.push_back(pos);
                break;
            }
        }
        for(int j=y; j<8; j++) {
            vector<int> pos({x, j});
            if(qpos.find(pos) != qpos.end()) {
                result.push_back(pos);
                break;
            }
        }
        
        // left to right diagonal
        for(int i=x, j=y; i>=0 && j>=0;) {
            vector<int> pos({i, j});
            if(qpos.find(pos) != qpos.end()) {
                result.push_back(pos);
                break;
            }
            i--; j--;
        }
        for(int i=x, j=y; i<8 && j<8; ) {
            vector<int> pos({i, j});
            if(qpos.find(pos) != qpos.end()) {
                result.push_back(pos);
                break;
            }
            i++; j++;
        }

        // right to left diagonal
        for(int i=x, j=y; i<8 && j>=0; ) {
            vector<int> pos({i, j});
            if(qpos.find(pos) != qpos.end()) {
                result.push_back(pos);
                break;
            }
            i++; j--;
        }

        for(int i=x, j=y; i>=0 && j<8; ) {
            vector<int> pos({i, j});
            if(qpos.find(pos) != qpos.end()) {
                result.push_back(pos);
                break;
            }
            i--; j++;
        }        
        return result;
    }
};