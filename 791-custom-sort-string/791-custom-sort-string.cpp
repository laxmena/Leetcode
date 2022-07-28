class Solution {
public:
    string customSortString(string order, string s) {
        queue<char> q; 
        int f[26] = {0};
        
        for(char c: order) q.push(c);
        for(char c: s) f[c-'a']++;
        
        string result = "";
        while(q.empty() == false) {
            char& c = q.front();
            q.pop();
            result += string(f[c-'a'], c);
            f[c-'a'] = 0;
        }
        for(int i=0; i<26; i++) {
            if(f[i] > 0) result += string(f[i], char(i+'a')); 
            f[i] = 0;
        }
        return result;
    }
};