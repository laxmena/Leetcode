class Solution {
public:
    string makeGood(string s) {
        string result = "";
        stack<char> stk;
        for(char c: s) {
            if(result.empty()) {
                result.push_back(c);
                continue;
            }
            if(c != result.back() && tolower(c) == tolower(result.back()))
                result.pop_back();
            else result.push_back(c);
        }
        return result;
    }
};