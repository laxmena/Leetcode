class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<deque<int>> result;
        int rows=nums.size();
        for(int r=0; r<rows; r++) {
            for(int c=0; c<nums[r].size(); c++) {
                
                while(result.size() <= (r+c)) {
                    deque<int> temp;
                    result.push_back(temp);
                }
                
                result[r+c].push_front(nums[r][c]);
            }
        }
        
        vector<int> answer;
        for(auto vec: result) {
            for(auto val: vec) {
                answer.push_back(val);
            }
        }
        return answer;
    }
};