class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> lmax(1, 0);
        int rmax = 0;
        int volume = 0;
        for(int h: height) lmax.push_back(max(lmax.back(), h));
        for(int i=height.size()-1; i>=0; i--) {
            rmax = max(rmax, height[i]);
            volume += min(lmax[i+1], rmax) - height[i];
        }
        return volume;
    }
};