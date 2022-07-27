class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap(begin(stones), end(stones));
        int s1, s2;
        while(heap.size() > 1) {
            s1 = heap.top(); heap.pop();
            s2 = heap.top(); heap.pop();
            if(s1 != s2) heap.push(abs(s1-s2));
        }
        return heap.size() == 0? 0: heap.top();
    }
};