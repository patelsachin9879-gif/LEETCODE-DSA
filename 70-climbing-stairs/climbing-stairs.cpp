class Solution {
public:
    int climbStairs(int n) {
        // Base cases: 1 way for 1 step, 2 ways for 2 steps
        if (n == 1 || n == 2) return n;
        
        int prev2 = 1; // Represents ways to reach (n-2) steps
        int prev1 = 2; // Represents ways to reach (n-1) steps
        int result = prev1;
        
        // Iteratively calculate ways for subsequent steps up to n
        for (int i = 3; i <= n; i++) {
            result = prev1 + prev2;
            prev2 = prev1; // Update for the next iteration
            prev1 = result; // Update for the next iteration
        }
        
        return result;
    }
};