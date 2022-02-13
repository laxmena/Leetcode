class Solution {
public:
    void gen_subset(vector<vector<int>> &prev, vector<int> &cand) {
        if(cand.size() == 0) return;
        int c = cand[0];
        vector<vector<int> > gen;
        for(auto vec: prev) {
            vec.push_back(c);
            gen.push_back(vec);
        }
        prev.insert(prev.end(), gen.begin(), gen.end());
        cand.erase(cand.begin());
        gen_subset(prev, cand);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > result;
        result.push_back(vector<int>());
        gen_subset(result, nums);
        return result;
    }
};