class Solution {
public:
    
    vector<int> mergevec(vector<int> first, vector<int> second) {
        return {min(first[0], second[0]), max(first[1], second[1])};
    }
    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> result;
        bool insert = false;
        
        for(int i=0; i<intervals.size() && !insert; i++) {
            if(intervals[i][0] >= newInterval[0]) {
                intervals.insert(begin(intervals) + i, newInterval);
                insert = true;
            }
        } 
        
        if(!insert) intervals.push_back(newInterval);
        
        for(int i=0; i<intervals.size(); i++) {
            if(result.empty()) {
                result.push_back(intervals[i]);
                continue;
            }    
            if(result.back()[1] >= intervals[i][0]) {
                vector<int> merge = mergevec(result.back(), intervals[i]);
                result.pop_back();
                result.push_back(merge);
            } else {
                result.push_back(intervals[i]);
            }
        }
        
        return result;
    }
};


/**
1 => [[1,2][3,4]] - [5,6] => [[1,2][3,4][5,6]]
2 => [[1,3][4,6]] - [2,5] => [[1,6]] 
3 => [[1,3][4,5]] - [4,7] => [[1,3][4,7]]
**/