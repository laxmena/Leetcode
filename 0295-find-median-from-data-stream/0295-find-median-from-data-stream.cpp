class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

    MedianFinder() {

    }
    
    void addNum(int num) {
        if(left.empty() || num < left.top()) left.push(num);
        else right.push(num);
        

        int leftSize = left.size(), rightSize = right.size();
        if(abs(leftSize - rightSize) > 1) {
            if(leftSize > rightSize) {
                right.push(left.top());
                left.pop();
            } else {
                left.push(right.top());
                right.pop();
            }
        }
    }
    
    double findMedian() {
        if(left.empty() && right.empty()) return 0;
        if(right.empty()) return left.top();

        if(left.size() == right.size()) 
            return (left.top() + right.top()) / 2.0;
        else if(left.size() > right.size()) return left.top();
        else return right.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */