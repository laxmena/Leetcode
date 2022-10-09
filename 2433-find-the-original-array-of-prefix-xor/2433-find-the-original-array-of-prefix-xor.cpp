class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        if(pref.size() == 0) return pref;

        vector<int> result;
        int val = 0;
        for(auto p: pref) {
            int elem = val ^ p;
            result.push_back(elem);
            val ^= elem;
        }
        return result;
    }
};