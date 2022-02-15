class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int map[128] = {0}, tmap[128] = {0};
        int slen = s.length();
        int tlen = t.length();
        if(slen != tlen) return false;

        char c1, c2;
        for(int i=0; i<slen; i++) {
            c1 = int(s[i]);
            c2 = int(t[i]);
            if(map[c1] != 0) {
                if(map[c1] != c2)
                    return false;
            } else {
                if(tmap[c2] != 0) return false;
                map[c1] = c2;
                tmap[c2] = c1;
            }
        }
        return true;
    }
};