class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> dir;
        for(string& log: logs) {
            if(log == "./") continue;
            if(log == "../") {
                if(!dir.empty()) {
                    dir.pop();
                }
            }
            else dir.push(log);
        }
        return dir.size();
    }
};