//Largest rectangle in histogram
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n, 0);   // Stores index of nearest smaller element to the left
        vector<int> right(n, 0);  // Stores index of nearest smaller element to the right
        stack<int> s;
        
        // 1. Find nearest smaller element to the right
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            right[i] = s.empty() ? n : s.top(); 
            s.push(i);
        }
        
        // CRITICAL FIX: Clear the stack before reusing it for the left side
        while (!s.empty()) {
            s.pop();
        }
        
        // 2. Find nearest smaller element to the left
        for (int i = 0; i < n; i++) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        
        // 3. Calculate max area
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            int currArea = heights[i] * width;
            ans = max(ans, currArea);
        }
        
        return ans;
    }
};