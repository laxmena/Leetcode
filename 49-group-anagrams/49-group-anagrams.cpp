class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string> > mem;
        
        for(auto s: strs) {
            // Sort s to get the key
            string str = s;
            sort(str.begin(), str.end());
            if(mem.find(str) != mem.end()) mem.emplace(str, vector<string>());
            mem[str].push_back(s);
        }
        
        vector<vector<string> > result;
        for(auto& [key, value]: mem) {
            result.push_back(value);
        }
        return result;
    }
};