class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for(auto& t: tasks) freq[t-'A']++;
        
        int maxT = 0, n_max = 0;
        for(int t: freq) maxT = max(maxT, t);
        for(int t: freq) if(t == maxT) n_max++;
            
        return max((int)tasks.size(), (maxT-1)*(n+1)+n_max);
    }
};