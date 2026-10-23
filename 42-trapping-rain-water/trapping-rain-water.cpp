class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int l = 0, r = n - 1;
        int lmax = 0, rmax = 0;
        
        while (l < r) {
            // Update the maximum heights found so far from left and right
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);
            
            // The water trapped depends on the smaller of the two boundary heights
            if (lmax < rmax) {
                ans += lmax - height[l];
                l++;
            } else {
                ans += rmax - height[r];
                r--;
            }
        }
        return ans;
    }
};