class Solution {
public:
//     int minSumOfLengths(vector<int>& arr, int target) {
//         priority_queue<pair<int, pair<int, int>>> pq;
        
//         int left = 0, right = 0;
//         int subsum = 0;
        
//         for(right=0; right < arr.size(); right++) {
//             subsum += arr[right];
//             if(subsum == target) {
//                 pq.push(make_pair(right-left+1, make_pair(left, right)));
//             }
//             while(subsum > target && left <= right) {
//                 subsum -= arr[left];
//                 if(subsum == target) {
//                     pq.push(make_pair(right-left+1, make_pair(left, right)));
//                 }
//                 left++;
//             }
//         }
        
//         while(!pq.empty()) {
//             pair<int, pair<int, int>> top = pq.top();
//             cout << top.first << " (" << top.second.first << ", " << top.second.second<< ")\n";
//             pq.pop();
//         }
//         return 2;
//     }
    int minSumOfLengths(vector<int>& arr, int target) {
        int ans = INT_MAX, prev_min = INT_MAX, left = 0, right = 0, curr = 0;
        queue<pair<int, int>> q;
        while(right < arr.size()) {
            curr += arr[right++];
            while(curr > target && left < right) 
                curr -= arr[left++];

            while(!q.empty() && q.front().second <= left) {
                prev_min = min(prev_min, q.front().second - q.front().first);
                q.pop();
            }
            if(curr == target) {
                if(prev_min != INT_MAX)
                    ans = min(ans, prev_min + right - left);
                q.emplace(left, right);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};