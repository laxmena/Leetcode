class RandomizedSet {
private:
    map<int, int> datamap;
    vector<int> datalist;
public:
    RandomizedSet() {
        datamap = map<int, int>();
        datalist = vector<int>();
    }
    
    bool insert(int val) {
        if(datamap.count(val))
            return false;
        datamap[val] = datalist.size();
        datalist.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(datamap.count(val) == 0) return false;
            
        // Get index of searching value
        int idx = datamap[val];
        datalist[idx] = datalist[datalist.size()-1];
        datalist.pop_back();
        datamap[datalist[idx]] = idx;        
        datamap.erase(val);
        return true;

    
    }
    
    int getRandom() {
        return datalist[rand() % datalist.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */