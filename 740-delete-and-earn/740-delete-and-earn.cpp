class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int arr[20001] = {0};
        for(int n: nums) arr[n] += n;
        arr[2] += arr[0];
        for(int i=3; i<20001; i++) {
            arr[i] += max(arr[i-3], arr[i-2]);
        }
        return max(arr[20000-1], arr[20000]);
    }
};