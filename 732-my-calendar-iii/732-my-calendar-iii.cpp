class MyCalendarThree {
private:
    map<int, int> diff;

public:
    MyCalendarThree() {}

    int book(int start, int end) {
        int cur = 0, res = 0;
        diff[start]++;
        diff[end]--;
        for (auto& [_, delta] : diff) {
            cur += delta;
            res = max(res, cur);
        }
        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */

// p |--|
// n     |--|

// p     |--| 
// n |--|

// p |--|
// n   |--|
    
// p |--|
// n   |--|

// p |---|
// n  |-|

//  |-|
// |---|

// |--|
// |--|

//     24     40           1
//               43 - 50   1
//        27     43        2
// 5  21                   2
//          30 40           3
//  14     29 


// (5, 10), (10, 20) (50, 60)
// (10, 40)
// (25, 55)