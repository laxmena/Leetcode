class Solution {
public:
    
    vector<vector<int>> helper(vector<int>& candidates, int idx, int target) {
        vector<vector<int>> result;
        for(int i=idx; i<candidates.size(); i++) {
            int val = candidates[i]; 
            if(val > target) return result;
            if(val == target) result.push_back({val});
            
            vector<vector<int>> temp = helper(candidates, i, target-val);
            
            if(!temp.empty()) {
                for(auto& r: temp) { 
                    r.push_back(val);
                }
                result.insert(end(result), begin(temp), end(temp));
            }
             
        }
        return result;        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(begin(candidates), end(candidates));
        return helper(candidates, 0, target);
    }
};