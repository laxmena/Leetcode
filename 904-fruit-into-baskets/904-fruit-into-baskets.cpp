class Solution {
public:
    int totalFruit(vector<int>& tree) {
        unordered_map<int, int> m;
        int minval = 0, maxsize = 0, index = 0;

        for(auto it : tree){
            if(!m.count(it) and m.size() == 2){
                int val, pos = INT_MAX;
                for(auto i : m){ // only 2 times that is constant
                    if(i.second < pos)
                        pos = i.second, val = i.first;
                }
                m.erase(val);
                minval = pos + 1;
            }
            m[it] = index;
            maxsize = max(maxsize, index - minval + 1);
            index++;
        }
        return maxsize;
    }
};