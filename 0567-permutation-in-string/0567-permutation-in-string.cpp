class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> hist(26, 0);
        if(s2.size() < s1.size()) return false;
        for(char c: s1) hist[c-'a']++;        

        int k = s1.size();
        vector<int> h2(26, 0);
        
        // init sliding window of size k
        for(int i=0; i<k; i++) {
            char c = s2[i];
            h2[c-'a']++;
        }
        if(h2 == hist) return true;
        
        for(int i=k; i<s2.size(); i++) {
            char c = s2[i];
            char prev = s2[i-k];
            h2[prev-'a']--;
            h2[c-'a']++;
            if(h2 == hist) return true;
        }
        
        return false;
    }
};