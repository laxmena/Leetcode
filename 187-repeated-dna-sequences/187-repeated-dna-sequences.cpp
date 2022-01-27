class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string, int > hash;
        vector<string> result;
        if(s.length() < 10) return result;
        // cout <<"len: " << s.length() << "\n";
        for(int i=0; i<s.length()-9; i++) {
            // cout << "iL " << i << "\n";
            string key = s.substr(i, 10);
            if(hash.find(key) == hash.end()) { hash[key] = 0; }
            hash[key]++;
            // cout << "inc key: " << key << "\n";
        }
        for(auto& [key, value]: hash) {
            if(value > 1) result.push_back(key);
        }
        return result;
    }
};