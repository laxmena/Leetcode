class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n), right(n);
        for(int i=0; i<n; i++) {
            if(i == 0) {
                left[i] = height[i];
                right[n-1-i] = height[n-1-i];
            }
            else {
                left[i] = max(left[i-1], height[i]);
                right[n-1-i] = max(right[n-i], height[n-1-i]);
            }
        }
        int result = 0;
        for(int i=0; i<n; i++) {
            result += (min(left[i], right[i]) - height[i]);
        }
        return result;
    }
};


// [0,1,0,2,1,0,1,3,2,1,2,1]
// [0,1,1,2,2,2,2,3,3,3,3,3]
// [3,3,3,3,3,3,3,3,2,2,2,1]
   
