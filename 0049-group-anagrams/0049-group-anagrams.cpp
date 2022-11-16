class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;
        
        for(string s: strs) {
            string copy = s;
            sort(begin(copy), end(copy));
            m[copy].push_back(s);
        }
        
        vector<vector<string>> result;
        for(auto const& kv: m) {
            result.push_back(kv.second);
        }
        
        return result;
    }
};