class Solution {
public:
    int mirrorReflection(int p, int q) {
        bool up = true;
        int count = 1;
        if(q == 0) return 0;

        int cur = q;
        
        while(cur%p != 0) {
            if((cur/p)%2 == 0) up = true;
            else up = false;            
            cur += q;
            count++;
        }
        
        int result = count%2 == 0? 2: 1;
        if(!up) result = 0;
        
        return result;
    }
};