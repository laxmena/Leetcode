class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        queue<int> q;
        int n = arr.size();
        int head = 0;
        while(head < n) {
            int cur = arr[head];
            q.push(cur);
            if(cur == 0) q.push(cur);
            int qtop = q.front();
            arr[head++] = qtop;
            q.pop();
        }
    }
};