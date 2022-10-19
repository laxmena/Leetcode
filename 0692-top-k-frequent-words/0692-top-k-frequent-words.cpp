class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for(string w: words) freq[w]++;
        priority_queue<pair<int, string>, vector<pair<int, string>>, MyComp> heap;
        for(auto &[key, value]: freq) {
            heap.push(make_pair(value, key));
            if(heap.size()>k) heap.pop();
        }
        vector<string> result;
        while(k--) {
            result.insert(result.begin(), heap.top().second);
            heap.pop();
        }
        return result;
    }
    struct MyComp {
        bool operator() (const pair<int, string>& a, const pair<int, string>& b) {
            if(a.first != b.first) {
                return a.first > b.first;
            }
            else {
                return a.second < b.second;
            }
        }
    };
};