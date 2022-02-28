/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int> flatten(vector<NestedInteger> &nestedList) {
        vector<int> flatList;
        for(auto item: nestedList) {
            if(item.isInteger()) { 
                flatList.push_back(item.getInteger());
                continue;
            } 
            vector<int> temp = flatten(item.getList());
            flatList.insert(flatList.end(), begin(temp), end(temp));
        }
        return flatList;
    }
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        flatList = flatten(nestedList);
        index = 0;
        size = flatList.size();
    }
    
    int next() {
        return flatList[index++]; 
    }
    
    bool hasNext() {
        return index < size;
    }
private:
    vector<int> flatList;
    int index, size;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */