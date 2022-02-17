class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> heap;
        int cost = 0;
        for(int s: sticks) heap.push(s);
        while(heap.size() > 1) {
            int min1 = heap.top(); heap.pop();
            int min2 = heap.top(); heap.pop();
            cost += min1 + min2;
            heap.push(min1 + min2);
        }
        return cost;
    }
};