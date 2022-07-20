class Solution {
public:
    map<char, vector<int>> loc;
    
    int getPosition(char c, int min) {
        for(auto val: loc[c]) {
            if(val > min) return val;
        }    
        return -1;
    }
    
    
    int numMatchingSubseq(string s, vector<string>& words) {
        int result = 0;
        
        for(int i=0; i<s.size(); i++) {
            loc[s[i]].push_back(i);
        }
        
        for(auto word: words) {
            int min = -1;
            for(char c: word) {
                min = getPosition(c, min);
                if(min == -1) break;
            }
            if(min != -1) result+=1;
        }
              
        return result;
    }
};