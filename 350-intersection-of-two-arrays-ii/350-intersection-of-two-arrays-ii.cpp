class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> freq, res;
        vector<int> result;

        for(auto n: nums1) {
            if(freq.find(n) == freq.end()) freq[n] = 0;
            freq[n]++;
        }
        for(auto n: nums2) {
            if(freq.find(n) != freq.end()) {
                if(res.find(n) == res.end()) res[n] = 0;
                res[n]++; freq[n]--;
                if(freq[n] == 0) freq.erase(n);
            }
        }
        for(auto& [key, value]: res) {
            for(int i=0; i<value; i++) result.push_back(key);
        }
        return result;
    }
};