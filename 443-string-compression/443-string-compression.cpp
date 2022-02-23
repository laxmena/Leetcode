class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size(), rep = 0;
        char prev = chars[0];        
        for(int i=0; i<n; i++) {
            if(prev == chars[i]) rep++;
            else {
                chars.push_back(prev);
                if(rep > 1) {
                    string count = to_string(rep);
                    for(char c: count) chars.push_back(c);
                }
                prev = chars[i]; rep = 1;
            }
        }
        chars.push_back(prev);
        if(rep > 1) {
            string count = to_string(rep);
            for(char c: count) chars.push_back(c);            
        }
        
        chars.erase(chars.begin(), chars.begin()+n);
        return chars.size();
    }

};