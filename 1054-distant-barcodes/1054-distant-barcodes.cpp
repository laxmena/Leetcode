class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        map<int, int> freq;
        for(auto code: barcodes) freq[code]++;
        
        // create heap
        priority_queue<pair<int, int>> heap;
        for(auto elem: freq) {
            heap.push(make_pair(elem.second, elem.first));
        }
        
        vector<int> result;
        pair<int, int> def = make_pair(0, 0);
        pair<int, int> q = def;
        while(heap.empty() == false) {
            pair<int, int> temp = heap.top();
            heap.pop();
            result.push_back(temp.second);

            if(q != def) heap.push(q);
            if(temp.first-1 > 0) {
                q = make_pair(temp.first-1, temp.second);                
            } else q = def;
        }
        
        if(q != def) result.push_back(q.second);
        
        return result;
    }
};