class Solution {
public:
    vector<int> findOriginalArray(vector<int>& arr) {
        sort(begin(arr), end(arr));
        
        map<int, int> freq;
        vector<int> result, temp;
        for(int n: arr) {
            if(n%2==0 && freq[(n/2)] > 0) {
                int half = n/2;
                // cout << "n: " << n << "\n";
                result.push_back(half);
                if(freq[half] == 1) {
                    // cout << "erasing: " << half <<"\n";
                    freq.erase(half);
                }
                else freq[half]--;
                // cout << freq.size() << " <- freq val \n";
            } else {
                freq[n]++;                
            }
        }
        
        bool res = true;
        for(auto const& [k, v]: freq) {
            res &= (v == 0);
        }
    
        
        return res? result: temp;
    }
};