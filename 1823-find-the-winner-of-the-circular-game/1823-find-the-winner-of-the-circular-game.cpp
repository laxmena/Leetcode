class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> arr;
        for(int i=0; i<n; i++) arr.push_back(i);
        int start = 0;
        int len = arr.size();
        while(len > 1) {
            int moves = k%len;
            int index = (len + start + moves - 1) % len;
            arr.erase(arr.begin() + index);
            len = arr.size();
            start = index % len;
        }
        return arr[0] + 1;
    }
};