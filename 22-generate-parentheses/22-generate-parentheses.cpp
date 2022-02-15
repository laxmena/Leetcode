class Solution {
public:
    set<string> recurse(string p, int open, int close) {
        set<string> s, s1;
        if((open > close)) return s;
        if(open == close && open == 0) s.insert(p);
        if(open) s = recurse(p + "(", open-1, close);
        s1 = recurse(p + ")", open, close-1);
        s.insert(s1.begin(), s1.end());
        return s;
    }
    vector<string> generateParenthesis(int n) {
        set<string> s;
        vector<string> result;
        s = recurse("", n, n);
        for(string i: s) result.push_back(i);
        return result;
    }
};