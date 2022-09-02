class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> scopy(begin(score), end(score));
        sort(begin(scopy), end(scopy), greater<int>());
        
        map<int, int> rank;
        for(int i=0; i<scopy.size(); i++) {
            rank[scopy[i]] = i+1;
        }
        
        vector<string> result;
        for(int sc: score) {
            int s = rank[sc];
            if(s == 1) result.push_back("Gold Medal");
            else if(s == 2) result.push_back("Silver Medal");
            else if(s == 3) result.push_back("Bronze Medal");
            else result.push_back(to_string(s));
        }
        return result;
    }
};