class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int one=0, flip=0;
        for(char c: s) {
            if(c == '1') one++;
            else flip++;
            flip = min(one, flip);
        }
        return flip;
    }
};