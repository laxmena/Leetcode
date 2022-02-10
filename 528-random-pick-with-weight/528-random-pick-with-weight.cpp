class Solution {
public:
    vector<int> prefix;
    int n;
    Solution(vector<int>& w) {
        int sum = 0;
        for(int i=0; i<w.size(); i++) {
            sum += w[i];
            prefix.push_back(sum);
            cout << prefix[prefix.size()-1] << " ";
        }
        cout << "\n";
        n = sum;
        cout << "sum: " << n << "\n";
    }
    
    int pickIndex() {
        int ridx = rand() % n;
        for(int i=0; i<prefix.size(); i++) {
            if(ridx < prefix[i]) return i;
        }
        return 0;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */