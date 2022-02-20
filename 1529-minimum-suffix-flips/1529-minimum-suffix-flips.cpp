class Solution {
public:
    int minFlips(string target) {
        int cnt = 0, state = 0;
        for (auto b : target)
            if (b - '0' != state) {
                state = b - '0';
                ++cnt;
            }
        return cnt;
    }
};