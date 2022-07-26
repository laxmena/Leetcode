class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int, int> freq;
        int result = 0;
        for(int task: tasks) freq[task]++;        
        for(auto each: freq) {
            if(each.second == 1) return -1;
            result += (each.second+2)/3;
        }
        return result;
    }
};