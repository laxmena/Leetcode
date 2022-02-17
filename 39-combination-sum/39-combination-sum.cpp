class Solution {
public:
    vector<vector<int>> recurse(vector<int>& cand, int idx, int target) {
        vector<vector<int>> result;
        if(target <= 0 && target < cand[0]) return result; // Recursion exit condition
        for(int j=idx; j<cand.size(); j++) {
            int num = cand[j];
            if(num == target) {
                vector<int> temp({target});
                result.push_back(temp);
            } else if(num < target) {
                vector<vector<int>> rec_res = recurse(cand, j, target-num);
                if(rec_res.size() > 0) {
                    for(int i=0; i<rec_res.size(); i++) {
                        rec_res[i].push_back(num);
                    }
                }
                result.insert(result.end(), rec_res.begin(), rec_res.end());
            }
        }
        return result;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > result = recurse(candidates, 0, target);
        return result;
    }
};