class Solution {
public:
    
    typedef pair<double, pair<int, int>> pii;
    
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue< pii, vector<pii>, greater<pii>  > pq;
        
        for(int i=0; i<n; i++){
            pq.push({(double)arr[i]/arr[n-1], {i, n-1}});
        }
        
        while(k > 1){
            auto top = pq.top();    pq.pop();
            int i = top.second.first;
            int j = top.second.second;
            pq.push({(double)arr[i]/arr[j-1], {i, j-1}});
            k--;
        }
        
        auto top = pq.top();
        return {arr[top.second.first], arr[top.second.second]};
    }
};