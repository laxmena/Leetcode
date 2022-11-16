class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        
        int l = 0, r = height.size() - 1;
        while(l < r) {
            maxWater = max(maxWater, (r-l)*min(height[r], height[l]));
            if(height[r] < height[l]) r--;
            else l++;
        }
        
        return maxWater;
    }
};