class Solution {
public:
    int maxPower(string s) {
        if(s.size() == 0)  return 0;
        int rep = 1, res = 1;
        for(int i=1; i<s.size(); i++) {
            if(s[i] == s[i-1]) rep++;
            else rep = 1;
            res = max(res, rep);
        }
        return res;
    }
};