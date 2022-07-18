class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        if (nums.empty() || nums[0].empty()) return {};
        vector<int> res;
        queue<pair<int,int>> q;
        q.push({0,0});
        while (!q.empty()) {
            auto [x,y] = q.front();
            res.push_back(nums[x][y]);
            if (x+1 < nums.size() && y == 0 ){ // node (x,y) is at the first column, add the new node below it.
                q.push({x+1,y});
            }
            if ( y+1 < nums[x].size() ){ // add the right neighbor node
                q.push({x,y+1});
            }
            q.pop();
        }
        return res;
        
    }
};