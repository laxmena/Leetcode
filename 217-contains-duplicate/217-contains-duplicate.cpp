class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> mem;
        for(int n: nums) {
            if(mem.find(n) != mem.end()) return true;
            mem.insert(n);
        }
        return false;
    }
};