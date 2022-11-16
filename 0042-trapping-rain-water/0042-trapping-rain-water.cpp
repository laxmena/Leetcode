class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(height.size(), 0);
        vector<int> right(height.size(), 0);
        for(int i=0; i<n; i++) {
            if(i == 0) left[i] = height[i];
            else left[i] = max(left[i-1], height[i]);
        }
        for(int i=n-1; i>=0; i--) {
            if(i == n-1) right[i] = height[i];
            else {
                right[i] = max(right[i+1], height[i]);
            }
        }
        
        int water = 0;
        for(int i=0; i<n; i++) {
            water += min(left[i], right[i]) - height[i];
            // if(val > 0) water += val;
        }
        return water;
    }
};