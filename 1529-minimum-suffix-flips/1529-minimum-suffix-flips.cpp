class Solution {
public:
    int minFlips(string target) {
        int cnt = 0;
        char state = '0';
        for (char b : target)
            if (b != state) {
                state = b;
                ++cnt;
            }
        return cnt;
    }
};