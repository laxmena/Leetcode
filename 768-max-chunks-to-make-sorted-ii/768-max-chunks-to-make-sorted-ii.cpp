class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> temp(begin(arr), end(arr));
        sort(begin(temp), end(temp));
        
        long long sum1 = 0, sum2 = 0, result = 0;
        for(int i=0; i<arr.size(); i++) {
            sum1 += arr[i];
            sum2 += temp[i];
            if(sum1 == sum2) result++;
        }
        return result;
    }
};