class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        set<int> mem;
        for(int n: arr) {
            if(mem.find(n*2) != mem.end() ||
                (n%2 == 0 && mem.find(n/2) != mem.end())) return true;
            mem.insert(n);
        }
        return false;
    }
};