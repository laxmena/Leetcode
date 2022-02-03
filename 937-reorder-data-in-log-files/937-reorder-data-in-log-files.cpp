class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        map<string, vector<string> > llogs;
        vector<string> dlogs;
        for(auto s: logs) {
            int sp = s.find(" ");
            if(s[sp+1] >= '0' && s[sp+1] <= '9') dlogs.push_back(s);
            else {
                string log = s.substr(sp+1);
                string id = s.substr(0, sp);
                llogs[s.substr(sp+1)].push_back(s.substr(0, sp));
            }
        }
        vector<string> result;
        for(auto& [key, value]: llogs) {
            sort(value.begin(), value.end());
            for(auto v: value) result.push_back(v + " " + key);
        }
        for(auto s: dlogs) result.push_back(s);
        return result;
    }
};