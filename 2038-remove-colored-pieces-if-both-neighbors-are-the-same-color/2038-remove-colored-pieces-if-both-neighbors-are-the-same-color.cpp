class Solution {
public:
    bool winnerOfGame(string colors) {
        int acount = 0, bcount = 0;
        int rep = 0;
        for(int i=1; i<colors.size(); i++) {
            if(colors[i] == colors[i-1]) {
                if(++rep > 1) {
                    if(colors[i] == 'A') acount++;
                    else bcount++;
                }
            } else {
                rep = 0;
            }
        }
        return acount > bcount;
    }
};