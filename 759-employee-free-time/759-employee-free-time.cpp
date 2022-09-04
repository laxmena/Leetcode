/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

bool compareInterval(const Interval& a, const Interval& b) {
    if(a.start == b.start) 
        return a.end < b.end;
    return a.start < b.start;
}

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> merge, result;
        int start = 0, endv = INT_MIN;
    
        for(auto emp: schedule) {
            merge.insert(end(merge), begin(emp), end(emp));
        }
        
        sort(begin(merge), end(merge), compareInterval);
        
        for(auto work: merge) {
            if(work.start < endv) {
                endv = max(endv, work.end);
            } else {
                start = endv;
                endv = work.start;
                if(start != endv) {
                    Interval interval(start, endv);
                    result.push_back(interval);
                }
                endv = work.end;
            }
        }
        
        result.erase(begin(result));
        return result;
    }
};