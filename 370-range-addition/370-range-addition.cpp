class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> result(length+1, 0);
        for(vector<int> update: updates) {
            result[update[0]] += update[2];
            result[update[1]+1] -= update[2]; 
        }
        // Add all the values
        int sum = 0;
        for(int i=0; i<length; i++) {
            sum += result[i];
            result[i] = sum;
        }
        result.erase(result.begin()+length);
        return result;
    }
};