class Solution {
public:
    int minFlips(string target) {
        int n = target.size();
        int ones = 0, onezeros = 0;
        ones += target[n-1]-'0';
        for(int i=0; i<target.size()-1; i++) {
            ones += target[i]-'0';
            if(target[i] == '1' && target[i+1] == '0') onezeros+=1;
        }
        if(ones == 0) return 0;
        return onezeros*2 + target[n-1]-'0';
    }
};