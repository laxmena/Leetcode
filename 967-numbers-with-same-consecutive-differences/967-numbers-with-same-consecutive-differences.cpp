class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        set<int> result;
        for(int i=1; i<10; i++) result.insert(i);
        
        while(n > 1) {
            set<int> temp;
            for(int val: result) {
                int digit = val % 10;
                if((digit - k) >= 0) {
                    temp.insert(val*10 + (digit-k));
                }
                if((digit + k) < 10) {
                    temp.insert(val*10 + (digit+k));
                }
            }
            result = temp;
            n -= 1;
        }
        
        vector<int> resvec(begin(result), end(result));
        return resvec;
    }
};
