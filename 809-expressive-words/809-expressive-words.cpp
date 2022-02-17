typedef vector<pair<char, int>> vp;
    
class Solution {
public:
    vp string_to_pair(string s) {
        vp result;
        char prev = s[0];
        int count = 0;

        for(char c: s) {
            if(prev == c) count++;
            else {
                result.push_back(make_pair(prev, count));
                prev = c; count = 1;
            }            
        }
        result.push_back(make_pair(prev, count));
        
        return result;
    }
    int expressiveWords(string s, vector<string>& words) {
        vp target = string_to_pair(s);
        int result = 0;
        for(string word: words) {
            vp dist = string_to_pair(word);
            if(target.size() != dist.size()) continue;
            bool flag = true; 
            for(int i=0; i<target.size() && flag; i++) {
                flag = (target[i].first == dist[i].first);
                if(target[i].second != dist[i].second) {
                    flag = (target[i].second > 2 && target[i].second >= dist[i].second);
                }
            }
            if(flag) result++;
        }
        return result;
    }
};

