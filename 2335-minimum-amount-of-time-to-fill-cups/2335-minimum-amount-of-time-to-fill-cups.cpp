class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> rem;
        int count = 0;
        for(auto i: amount) {
            if(i != 0) rem.push(i);
        }
        while(rem.size() > 1) {
            count++;
            int val1 = rem.top()-1;
            rem.pop();
            int val2 = rem.top()-1;
            rem.pop();
            if(val1 > 0) rem.push(val1);
            if(val2 > 0) rem.push(val2);
        }
        if(rem.size() == 1) count += rem.top();
        return count;
    }
};