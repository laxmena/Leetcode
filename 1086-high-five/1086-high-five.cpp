class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int, priority_queue<int>> item_store;
        for(vector<int> item: items) {
            item_store[item[0]].push(item[1]);
        }
        
        vector<vector<int> > result;
        for(auto &[key, value]: item_store) {
            vector<int> temp;
            temp.push_back(key);
            int sum = 0;
            for(int i=0; i<5; i++) {
                sum += item_store[key].top();
                item_store[key].pop();
            }
            temp.push_back(sum/5);    
            result.push_back(temp);
        }
        return result;
    }
};