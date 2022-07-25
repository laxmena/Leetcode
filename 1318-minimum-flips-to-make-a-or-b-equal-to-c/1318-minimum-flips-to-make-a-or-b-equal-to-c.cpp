class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count = 0;
        
        map<vector<int>, int> res;
        res[vector<int>({0, 0, 0})] = 0;
        res[vector<int>({0, 0, 1})] = 1;
        res[vector<int>({0, 1, 0})] = 1;
        res[vector<int>({0, 1, 1})] = 0;
        res[vector<int>({1, 0, 0})] = 1;
        res[vector<int>({1, 0, 1})] = 0;
        res[vector<int>({1, 1, 0})] = 2;
        res[vector<int>({1, 1, 1})] = 0;
        
        while(a>0 || b>0 || c>0) {
            count += res[vector<int>({a&1, b&1, c&1})];
            a = a>>1;
            b = b>>1;
            c = c>>1;
        }
        return count;
    }
};

