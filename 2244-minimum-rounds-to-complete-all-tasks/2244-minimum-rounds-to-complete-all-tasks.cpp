class Solution {
public:
    int reduce(int val) {
        if(val == 1) return -1;
        if(val%3 == 0) return val/3;
        if(val%2 == 1) {
            return 1 + reduce(val-3);
        }
        return 1 + reduce(val-2);
    }
    
    int minimumRounds(vector<int>& tasks) {
        map<int, int> freq;
        int result = 0;
        for(int task: tasks) freq[task]++;        
        for(auto each: freq) {
            if(each.second == 1) return -1; 
            result += reduce(each.second);
        }
        return result;
    }
};