class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(begin(words), end(words), [](auto &a, auto &b){ return a.size() < b.size(); });
        unordered_set<string> s{""};
        string res;
        for (auto &w : words)
            if (s.count(w.substr(0, w.size() - 1))) {
                s.insert(w);
                if (res.size() < w.size() || w < res)
                    res = w;
            }
        return res;
    }
};