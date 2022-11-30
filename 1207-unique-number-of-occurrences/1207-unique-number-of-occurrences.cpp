class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> hist;
        for(int n: arr) hist[n]++;
        set<int> dup;
        for(auto const& e: hist) {
            if(dup.count(e.second) > 0) return false;
            dup.insert(e.second);
        }
        return true;
    }
};