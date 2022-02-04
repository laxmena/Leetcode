class Solution {
public:
    int countBinarySubstrings(string s) {
        int z = 0, o = 0;
        bool zinc = false, oinc = false;
        int count = 0;
        for(auto ch: s) {
            int c = ch - '0';
            if(c == 0) {
                if(!zinc && z!=0) z = 0;
                z++;
                if(o) { count++; o--; }
                oinc = false;
                zinc = true; // zcount is increasing
            } else {
                if(!oinc && o != 0) o = 0;
                o++;
                if(z) { count++; z--; zinc=false; }
                oinc = true;
            }
        }
        return count;
    }
};