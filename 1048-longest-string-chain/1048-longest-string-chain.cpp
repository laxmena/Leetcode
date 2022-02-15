class Solution {
public:
    static bool compare(string &s1,string &s2) {
        return s1.size() < s2.size();
    }
    
    int longestStrChain(vector<string>& words) {
        sort(begin(words), end(words), compare);
        map<string, int> dp;
        int maxCount = 0;        
        for(int i=0; i<words.size(); i++) {
            string word = words[i];
            if(dp.find(word) != dp.end()) continue;
            int count = 0;
            
            for(int j=0; j<word.size(); j++) {
                string sstr = word.substr(0,j) + word.substr(j+1);
                if(dp.find(sstr) != dp.end()) {
                    count = max(count, dp[sstr]);
                }
            }
            
            // insert into map
            dp[word] = count + 1;
            maxCount = max(maxCount, dp[word]);
        }
        return maxCount;
    }
};