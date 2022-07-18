class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        int MOD = 1000000007;
        priority_queue<int, vector<int>, greater<int>> minheap(begin(nums), end(nums));
        int top;
        while(k--) {
            top = minheap.top();
            minheap.pop(); 
            minheap.push(top+1);
        }
        long result = 1;
        while(!minheap.empty()) {
            result = (result%MOD)*(minheap.top()%MOD);
            minheap.pop();
        }
        return result%MOD;
    }
};