class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> heap(begin(piles), end(piles));
        int sum = 0;
        // accumulate(begin(piles), end(piles), sum);
        while(k--) {
            int top = heap.top();
            heap.pop();
            // sum -= floor(top/2);
            top -= floor(top/2);
            heap.push(top);
        }
        int result = 0;
        while(heap.empty() == false) {
            result += heap.top();
            heap.pop();
        }
        return result;
    }
};