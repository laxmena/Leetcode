class Solution {
public:
    void appendData(string& temp, char c, int n) {
        temp.push_back('0' + n);
        temp.push_back(c);        
    }
    
    string countAndSay(int n) {
        string res = "1";
        
        for(int i=0; i<n; i++) {
            if(i == 0) continue;
            int count = 1;
            string temp = "";
            for(int j=1; j <= res.size(); j++) {
                if(j == res.size() || res[j] != res[j-1]) {
                    appendData(temp, res[j-1], count);
                    count = 0;
                }                
                count++;
            }
            res = temp;
        }
        
        return res;
    }
};
