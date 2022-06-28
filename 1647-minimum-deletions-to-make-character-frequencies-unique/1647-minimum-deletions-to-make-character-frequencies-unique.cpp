class Solution {
public:
    int minDeletions(string s) {
        vector<int> v(26, 0);
        for(char c: s) v[c-'a'] += 1;
        set<int> prev;
        int result = 0;
        
        for(int i=0; i<v.size(); i++) {
            int freq = v[i];
            if(freq == 0) continue;
            
            if(prev.count(freq) == 0) {
                prev.insert(freq);
                continue;
            }
            
            while(freq > 0 && prev.count(freq) != 0) {
                result += 1;
                freq -= 1;
            }
            prev.insert(freq);
        }        
        return result;
    }
};