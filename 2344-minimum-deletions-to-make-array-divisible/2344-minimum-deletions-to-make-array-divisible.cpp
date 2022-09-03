class Solution {
public:
    int gcd(int a, int b) {
        return b==0? a: gcd(b, a%b);
    }
    
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int gcdval = numsDivide[0];
        for(int num: numsDivide) gcdval = gcd(num, gcdval);
        
        map<int, int> freq;
        for(int num: nums) freq[num]++;
        
        cout << gcdval << "\n";
        
        int remove = 0;
        if(gcdval == 1) {
            if(freq.find(1) != freq.end()) return 0;
            else return -1;
        }
        
        for(auto const& obj: freq) {
            cout << obj.first << " " << obj.second << "\n";
            int num = obj.first;
            if(num%gcdval == 0 || gcdval%num==0) return remove;
            else remove += obj.second;
            if(num > gcdval) return -1;
        }
        return -1;
    }
};