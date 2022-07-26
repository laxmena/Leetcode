class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> heap(begin(piles), end(piles));
        int sum = accumulate(begin(piles), end(piles), 0);
        while(k--) {
            int top = heap.top();
            heap.pop();
            sum -= floor(top/2);
            top -= floor(top/2);
            heap.push(top);
        }
        return sum;
    }
};