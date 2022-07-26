class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> heap;
        heap.push(a); heap.push(b); heap.push(c);
        int count = 0;
        while(heap.size() > 1) {
            int one = heap.top(); heap.pop();
            int two = heap.top(); heap.pop();
            if(one > 1) heap.push(one-1);
            if(two > 1) heap.push(two-1);
            count++;
        }
        return count;
    }
};