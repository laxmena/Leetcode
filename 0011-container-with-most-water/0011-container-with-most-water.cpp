class Solution {
public:
    int maxArea(vector<int>& height) {
        long long maxWater = 0;
        
        int l = 0, r = height.size() - 1;
        while(l < r) {
            if(maxWater < (r-l)*min(height[r], height[l]))
                maxWater = (r-l)*min(height[r], height[l]);
            if(height[r] < height[l]) r--;
            else l++;
        }
        
        return maxWater;
    }
};