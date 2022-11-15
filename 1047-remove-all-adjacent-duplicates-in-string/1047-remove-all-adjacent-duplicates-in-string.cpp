class Solution {
public:
    string removeDuplicates(string s) {
        string q;
        for(char c: s) {
            if(q.back() == c) {
                q.pop_back();
            } else {
                q.push_back(c);                
            }
        }
        return q;
    }
};